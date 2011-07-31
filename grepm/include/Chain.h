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
 * File:   Chain.h
 * Author: Marco Ambu
 *
 * Created on July 31, 2011, 1:15 PM
 */

#ifndef _CHAIN_H
#define	_CHAIN_H

#include <cassert>

template <class ChainElement>
class Chain
{
public:
  Chain(ChainElement* root = NULL)
    : root_(root)
  {}
	virtual ~Chain() {}

	void add(ChainElement* element)
	{
		if (root_)
			root_->add(element);
		else
			root_ = element;
	}

	bool empty() const { return !root_; }

  ChainElement* getRoot() { return root_; }

private:
	ChainElement* root_;
};

#endif	// _CHAIN_H
