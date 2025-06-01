#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	_rawBits = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{	
	if (this != &other)
		_rawBits = other.getRawBits();
	return *this;
}

