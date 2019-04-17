//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_4__SHARPIE_SHARPIE_H
#define INC_4__SHARPIE_SHARPIE_H

#include <iostream>

class Sharpie {
public:
    Sharpie (std::string color, float width);

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


#endif //INC_4__SHARPIE_SHARPIE_H
