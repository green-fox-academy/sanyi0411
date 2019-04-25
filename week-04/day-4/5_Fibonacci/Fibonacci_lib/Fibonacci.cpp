//
// Created by sando on 2019. 04. 25..
//

#include <iostream>
#include "Fibonacci.h"

int Fibonacci::fibonacci (int n) {
    if (n >= 0) {
        if (n > 2) {
            return (fibonacci(n - 2) + fibonacci(n - 1));
        } else if (n == 1 || n == 2) {
            return 1;
        } else {
            return 0;
        }
    } else {
        throw std::invalid_argument( "received negative value" );
    }
}

