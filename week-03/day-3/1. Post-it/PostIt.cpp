//
// Created by sando on 2019. 04. 17..
//

#include "PostIt.h"
#include <iostream>

PostIt::PostIt(std::string bColor, std::string text, std::string textColor)
{
    _backgroundColor = bColor;
    _text = text;
    _textColor = textColor;
}

PostIt::PostIt()
{
    _backgroundColor = "#ffffff";
    _text ="Hello World";
    _textColor = "#000000";
}

std::string PostIt::getBackgroundColor()
{
    return _backgroundColor;
}

std::string PostIt::getText()
{
    return _text;
}

std::string PostIt::getTextColor()
{
    return _textColor;
}

void PostIt::setBackgroundColor(std::string backgroundColor)
{
    this->_backgroundColor = backgroundColor;
}

void PostIt::setText(std::string text)
{
    this->_text = text;
}

void PostIt::setTextColor(std::string textColor)
{
    this->_textColor = textColor;
}
