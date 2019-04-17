//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_8__DICE_SET_DICESET_H
#define INC_8__DICE_SET_DICESET_H

#include <iostream>
#include <vector>

class DiceSet
{
public:

    DiceSet();

    void roll();
    void roll(int i);
    std::vector<int> getCurrent() const;
    int getCurrent(int i) const;
private:
    std::vector<int> dices;
};

#endif //INC_8__DICE_SET_DICESET_H
