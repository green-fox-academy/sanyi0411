//
// Created by sando on 2019. 04. 18..
//

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width, int inkAmount)
{
    _color = color;
    _width = width;
    _inkAmount = inkAmount;
}

void Sharpie::setColor(std::string &color)
{
    Sharpie::_color = color;
}

void Sharpie::setWidth(float width)
{
    Sharpie::_width = width;
}

void Sharpie::setInkAmount(float inkAmount)
{
    Sharpie::_inkAmount = inkAmount;
}

std::string Sharpie::getColor()
{
    return _color;
}

float Sharpie::getWidth()
{
    return _width;
}

float Sharpie::getInkAmount()
{
    return _inkAmount;
}

void Sharpie::use()
{
    float ink = getInkAmount();
    setInkAmount(ink-1);
}