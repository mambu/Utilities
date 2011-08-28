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

void usage()
{
   std::cout << "Usage: grepm [Options] pattern [filename]" << std::endl;
   std::cout << "Parameters:" << std::endl;
   std::cout << "\tpattern\tPattern to search for" << std::endl;
   std::cout << "\tfilename\tFile to read from" << std::endl;
   std::cout << "Options:" << std::endl;
   std::cout << "\t-h\tPrint help and exit" << std::endl;
   std::cout << "\t-n\tPrint line numbers" << std::endl;
   std::cout << "\t-s\tPrint summary at the end" << std::endl;
}

int main(int argc, char* argv[])
{
  if (argc == 2 && std::string(argv[1]) == "-h")
  {
    usage();
    return 0;
  }

  if (argc < 2)
  {
    usage();
    return 1;
  }

  // parse options
  bool lineNumbers = false;
  bool summary = false;

  int i = 1;
  while ((i < argc - 1) && std::string(argv[i]).size() == 2 && argv[i][0] == '-')
  {
    switch (argv[i][1])
    {
      case 'n':
        lineNumbers = true;
        break;
      case 's':
        summary = true;
        break;
      default:
        break;
    }
    ++i;
  }

  std::string pattern = argv[i];

  // Preprocessing
  LineCount lineCount;

  // Filtering
  BoostGrep grep(pattern);

  //Postprocessing
  LineNumber lineNumber;

  // Buffering
  MultiGrep multiGrep(0);

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
