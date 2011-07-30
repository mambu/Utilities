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
 * File:   CircBuffer.h
 * Author: Marco Ambu
 *
 * Created on July 29, 2011, 7:00 PM
 */

#ifndef _CIRCBUFFER_H
#define	_CIRCBUFFER_H

#include <deque>
#include <string>

class CircBuffer
{
public:
    CircBuffer(std::size_t capacity);

    bool empty() const;
    std::size_t size() const;
    // add the newest element to the buffer
    void add(const std::string& value);
    // removes the oldest element form the buffer
    bool shift();

    // get the oldest element in the buffer
    const std::string& get() const;
    const std::string& get(std::size_t index) const;

private:
    std::size_t capacity_;
    std::deque<std::string> deque_;
};

#endif	// _CIRCBUFFER_H
