//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_9__DOMINOES_DOMINO_H
#define INC_9__DOMINOES_DOMINO_H

#include <iostream>
#include <utility>

class Domino
{
public:
    Domino(int valueA, int valueB);

    std::pair<int,int> getValues();
    std::string toString();

private:
    std::pair<int,int> _values;
};

#endif //INC_9__DOMINOES_DOMINO_H
