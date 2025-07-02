#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{	
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value  * 256;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * 256);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}


Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->_rawBits * other._rawBits) / 256);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits((this->_rawBits * 256) / other._rawBits);
    return result;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_rawBits < other._rawBits;
}
bool Fixed::operator>(const Fixed& other) const
{
	return this->_rawBits > other._rawBits;
}
bool Fixed::operator<=(const Fixed& other) const
{
	return this->_rawBits <= other._rawBits;
}
bool Fixed::operator>=(const Fixed& other) const
{
	return this->_rawBits >= other._rawBits;
}
bool Fixed::operator==(const Fixed& other) const
{
	return this->_rawBits == other._rawBits;
}
bool Fixed::operator!=(const Fixed& other) const
{
	return this->_rawBits != other._rawBits;
}

Fixed& Fixed::operator++()
{
	++_rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_rawBits++;
	return temp;
}

Fixed& Fixed::operator--()
{
	--_rawBits;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
float Fixed::toFloat( void ) const
{
	return static_cast<float>(_rawBits) / 256;
}
int Fixed::toInt( void ) const
{
	return _rawBits >> _fractional;
}