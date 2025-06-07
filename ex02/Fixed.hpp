#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);

        Fixed operator-(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

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