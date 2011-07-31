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


/* 
 * File:   LineCount.h
 * Author: Marco Ambu
 *
 * Created on July 31, 2011, 10:48 AM
 */

#ifndef _LINECOUNT_H
#define	_LINECOUNT_H

#include <StringProcessor.h>

class LineCount : public StringProcessor
{
public:
  LineCount()
    : count_(0)
  {}

  void process(std::string& /*line*/)
  {
    ++count_;
  }

  std::size_t getCount() const { return count_; }

private:
  std::size_t count_;
};

#endif	// _LINECOUNT_H
