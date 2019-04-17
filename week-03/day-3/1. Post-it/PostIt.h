//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_1__POST_IT_POSTIT_H
#define INC_1__POST_IT_POSTIT_H

#include <iostream>

class PostIt {
public:
    PostIt(std::string bColor, std::string text, std::string textColor);
    PostIt();
    std::string getBackgroundColor();
    std::string getText();
    std::string getTextColor();

    void setBackgroundColor(std::string backgroundColor);
    void setText(std::string text);
    void setTextColor(std::string textColor);

private:
    std::string _backgroundColor;
    std::string _text;
    std::string _textColor;

};


#endif //INC_1__POST_IT_POSTIT_H
