#include <iostream>
#include "Point.hpp"
// #include "bsp.cpp"   // If bsp is in its own header

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point p1(1, 1);  // Inside triangle
    Point p2(5, 5);  // Outside triangle

    if (bsp(a, b, c, p1))
        std::cout << "Point p1 is inside the triangle." << std::endl;
    else
        std::cout << "Point p1 is outside the triangle." << std::endl;

    if (bsp(a, b, c, p2))
        std::cout << "Point p2 is inside the triangle." << std::endl;
    else
        std::cout << "Point p2 is outside the triangle." << std::endl;

    return 0;
}
