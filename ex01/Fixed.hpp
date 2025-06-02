#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        // std::string operator<<(const Fixed& fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        private:
        int _rawBits;
        static const int _fractional = 8;
}; 

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif