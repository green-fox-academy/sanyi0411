//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_5__COUNTER_COUNTER_H
#define INC_5__COUNTER_COUNTER_H
#include <iostream>


class Counter {
public:
    Counter (int input);
    Counter ();

    int getNumber();

    void setNumber(int number);

    void add(int number);

    void add();

    int get();

    void reset();

private:
    int _resetValue;
    int _number;
};


#endif //INC_5__COUNTER_COUNTER_H
