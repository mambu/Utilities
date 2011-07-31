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
 * File:   ChainItem.h
 * Author: Marco Ambu
 *
 * Created on July 31, 2011, 1:12 PM
 */

#ifndef _CHAINITEM_H
#define	_CHAINITEM_H

#include <stdexcept>

class ChainItem
{
public:
  ChainItem()
    : next_(NULL)
  {}
	virtual ~ChainItem() {}

protected:
	void add(ChainItem* next)
  {
		if (next == this)
			throw std::logic_error("Cannot add a ChainItem as a child of itself");
		if (next_)
			next_->add(next);
		else
			next_ = next;
	}

protected:
	ChainItem* next_;

private:
	template<class> friend class Chain;
};

#endif	// _CHAINITEM_H
