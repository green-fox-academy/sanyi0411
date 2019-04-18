//
// Created by sando on 2019. 04. 18..
//

#ifndef INC_11__SHARPIE_SET_SHARPIE_H
#define INC_11__SHARPIE_SET_SHARPIE_H

#include <iostream>

class Sharpie {
public:
    Sharpie (std::string color, float width, int inkAmount);

    void setColor(std::string &color);
    void setWidth(float width);
    void setInkAmount (float inkAmount);

    std::string getColor();
    float getWidth();
    float getInkAmount();

    void use();

private:
    std::string _color;
    float _width;
    float _inkAmount;
};


#endif //INC_11__SHARPIE_SET_SHARPIE_H
