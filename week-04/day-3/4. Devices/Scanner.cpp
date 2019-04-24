//
// Created by sando on 2019. 04. 24..
//

#include "Scanner.h"

Scanner::Scanner(int speed)
{
    _speed = speed;
}

void Scanner::scan()
{
    std::cout << "I'm scanning a document " << _speed << " ppm\n";
}
