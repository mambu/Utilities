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
#include <Grep.h>
#include <iostream>
#include <fstream>
#include <string>

void usage()
{
   std::cout << "Usage: grepm pattern [filename]" << std::endl;
   std::cout << "Parameters:" << std::endl;
   std::cout << "\tpattern\tPattern to search for" << std::endl;
   std::cout << "\tfilename\tFile to read from" << std::endl;
   std::cout << "Options:" << std::endl;
   std::cout << "\t-h\tPrint help and exit" << std::endl;
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

  std::string pattern = argv[1];

  Grep grep(pattern);
  MultiGrep multiGrep(grep, 2);

  std::string line;
  std::string parsedLine;
  while (getline(std::cin, line))
  {
    multiGrep.process(line);
    while(multiGrep.hasNext())
    {
      multiGrep.getNext(parsedLine);
      std::cout << parsedLine << std::endl;
    }
  }

  return 0;
}
