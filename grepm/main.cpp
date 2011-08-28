/*
grepm: Command line utility similar to grep that prints surrounding lines

The MIT License
Copyright (c) 2011 Marco Ambu

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

 */

#include <MultiGrep.h>
#include <BoostGrep.h>
#include <LineNumber.h>
#include <LineCount.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <boost/program_options.hpp>
#include <boost/program_options/positional_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
  int bufferSize;

  po::options_description genericOpts("Generic options");
  genericOpts.add_options()
    ("help,h", "produce help message")
    //("verbose,v", "produce verbose output")
;
  po::options_description parsingOpts("Parsing options");
  parsingOpts.add_options()
    ("buffer-size,b", po::value<int>(&bufferSize)->default_value(2), "Buffer size (how many lines to print before and after matching line)")
    ("line-num,n", "Print line numbers")
    ("summary,s", "Print summary at the end")
;
  po::options_description hiddenOpts("Hidden"); // Positional parameters
  hiddenOpts.add_options()
      ("regex-pattern", po::value<std::string>(), "")
      ("input-file", po::value<std::string>(), "")
;
  po::positional_options_description pd;
  pd.add("regex-pattern", 1);//.add("input-file", 1);

  po::options_description visibleOpts("");
  visibleOpts.add(genericOpts).add(parsingOpts);

  po::options_description cmdLineOpts;
  cmdLineOpts.add(genericOpts).add(parsingOpts).add(hiddenOpts);
  po::variables_map vm;
  try
  {
    po::store(po::command_line_parser(argc, argv).options(cmdLineOpts).positional(pd).run(), vm);
    po::notify(vm);
  }
  catch(const po::error& e)
  {
    std::cout << "Usage: grepm [Options] regex-pattern" << std::endl;
    std::cout << visibleOpts << std::endl;
    return 1;
  }

  if (vm.count("help"))
  {
    std::cout << "Usage: grepm [Options] regex-pattern" << std::endl;
    std::cout << visibleOpts << std::endl;
    return 0;
  }
  
  if (vm.count("regex-pattern") == 0)
  {
    std::cout << "Usage: grepm [Options] regex-pattern" << std::endl;
    std::cout << visibleOpts << std::endl;
    return 1;
  }

  bool lineNumbers = vm.count("line-num");
  bool summary = vm.count("summary");
  std::string pattern = vm["regex-pattern"].as<std::string>();

  // Preprocessing
  LineCount lineCount;

  // Filtering
  BoostGrep grep(pattern);

  //Postprocessing
  LineNumber lineNumber;

  // Buffering
  MultiGrep multiGrep(bufferSize);

  std::string line;
  while (getline(std::cin, line))
  {
    lineCount.process(line);
    bool filterRes = grep.process(line);
    if (lineNumbers)
    {
      lineNumber.process(line);
    }
    multiGrep.process(line, filterRes);
    while(multiGrep.hasNext())
    {
      multiGrep.getNext(line);
      std::cout << line << std::endl;
    }
  }
  if (summary)
  {
    std::cout << "==================" << std::endl;
    std::cout << "Line count: " << lineCount.getCount() << std::endl;
  }

  return 0;
}
