#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int _rawBits;
        static const int _fractional;
}; 


#endif