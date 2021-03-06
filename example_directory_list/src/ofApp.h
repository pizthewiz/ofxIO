// =============================================================================
//
// Copyright (c) 2009-2013 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include <deque>
#include "ofMain.h"
#include "ofxIO.h"


using namespace ofx::IO;


// a custom hidden path filter
class CustomPathFilter: public AbstractPathFilter
{
public:
    CustomPathFilter()
    {
    }

    virtual ~CustomPathFilter()
    {
    }

    bool accept(const Poco::Path& path) const
    {
        // don't return hidden files or files with names containing "FilterMeOut
        return !Poco::File(path).isHidden() &&
               !ofIsStringInString(path.toString(), "FilterMeOut");
    }
};


class ofApp: public ofBaseApp
{
public:
    enum
    {
        TXT_HEIGHT = 14
    };

    void setup();
    void draw();

    void gotMessage(ofMessage msg);
    
    CustomPathFilter pathFilter; // an example path filter
    std::deque<std::string> messages;

    ByteBuffer buffer;

};
