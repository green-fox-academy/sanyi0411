#include <iostream>
#include <string>
#include <math.h>

int main(int argc, char* args[]) {

    int a = 3;
    // make the "a" variable's value bigger by 10
    a += 10;

    std::cout << a << std::endl;

    int b = 100;
    // make b smaller by 7
    b -= 7;

    std::cout << b << std::endl;

    int c = 44;
    // please double c's value
    c *= 2;

    std::cout << c << std::endl;

    int d = 125;
    // please divide by 5 d's value
    d /= 5;

    std::cout << d << std::endl;

    int e = 8;
    // please cube of e's value
    e = e*e;

    std::cout << e << std::endl;

    int f1 = 123;
    int f2 = 345;
    // tell if f1 is bigger than f2 (print as a boolean)
    bool f = f1 > f2;
    std::cout << f << std::endl; //should output 0 (false)

    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)
    bool g = (2 * g2) > g1;
    std::cout << g << std::endl; //should output 1 (true)

    int h = 135798745;
    // tell if it has 11 as a divisor (print as a boolean)
    bool hb = (h % 11) == 0;
    std::cout << hb << std::endl; //should output 0 (false)

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
    bool i = pow (i2, 2) < i1 && pow (i2, 3) > i1;
    std::cout << i << std::endl; //should output 1 (true) (10 is greater than 3^2 but smaller than 3^3)

    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)
    bool jb = j % 3 == 0 || j % 5 ==0;
    std::cout << jb << std::endl; //should output 1 (true) (1521 is not dividable by 5 but it is by 3)

    return 0;
}