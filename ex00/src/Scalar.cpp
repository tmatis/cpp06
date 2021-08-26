#include "Scalar.hpp"
#include <limits.h>
#include <math.h>

/* ************************************************************************** */
/*                                OUTTER FONCTIONS                            */
/* ************************************************************************** */
void	Scalar::printChar(std::ostream &os, const Scalar &i)
{
	os << "char: ";
	try
	{
		char c = static_cast<char>(i);
		if (std::isprint(c))
			os << c;
		else
			os << "Non displayable";
	}
	catch (std::exception &e)
	{
		os << "Impossible: " << e.what();
	}
	os << std::endl;
}

void	Scalar::printInt(std::ostream &os, const Scalar &i)
{
	os << "int: ";
	try
	{
		int n = static_cast<int>(i);
		os << n;
	}
	catch (std::exception &e)
	{
		os << "Impossible: " << e.what();
	}
	os << std::endl;
}

void	Scalar::printFloat(std::ostream &os, const Scalar &i)
{
	os << "float: ";
	float f = static_cast<float>(i);
	if (isinff(f) == 1)
		os << "+inf";
	else if (isinff(f) == -1)
		os << "-inf";
	else if (isnanf(f) == 1)
		os << "nan";
	else
	{
		os << f;
		if (f == 0)
			os << ".0";
	}
	os << "f" <<std::endl;
}

void   Scalar::printDouble(std::ostream &os, const Scalar &i)
{
	os << "double: ";
	double d = static_cast<double>(i);
	if (isinff(d) == 1)
		os << "+inf";
	else if (isinff(d) == -1)
		os << "-inf";
	else if (isnan(d) == 1)
		os << "nan";
	else
	{
		os << d;
		if (d == 0)
			os << ".0";
	}
	os << std::endl;
}

/* ************************************************************************** */
/*                                     DATA INIT                              */
/* ************************************************************************** */
/* ************************************************************************** */
/*                           CONSTRUCTOR - DESTRUCTOR                         */
/* ************************************************************************** */

Scalar::Scalar(std::string const & num)
{
	_value = atof(num.c_str());
}

Scalar::Scalar(void) : _value(0)
{
	
}

Scalar::Scalar(const Scalar &src)
{
	*this = src;
}

Scalar::~Scalar(void)
{

}

/* ************************************************************************** */
/*                              OVERLOAD FONCTIONS                            */
/* ************************************************************************** */

Scalar	&Scalar::operator=(const Scalar &right)
{
	this->_value = right._value;
	return (*this);
}

Scalar::operator float(void) const
{
	return (static_cast<float>(this->_value));
}

Scalar::operator double(void) const
{
	return (static_cast<double>(this->_value));
}

Scalar::operator int(void) const
{
	if (isnan(this->_value))
		throw Scalar::NotANumberException();
	if (this->_value > static_cast<double>(INT_MAX))
		throw Scalar::TooBigException();
	if (this->_value < static_cast<double>(INT_MIN))
		throw Scalar::TooSmallException();
	return (static_cast<int>(this->_value));
}

Scalar::operator char(void) const
{
	if (isnan(this->_value))
		throw Scalar::NotANumberException();
	if (this->_value > static_cast<double>(CHAR_MAX))
		throw Scalar::TooBigException();
	if (this->_value < static_cast<double>(CHAR_MIN))
		throw Scalar::TooSmallException();
	return (static_cast<char>(this->_value));
}



std::ostream	&operator<<(std::ostream &os, const Scalar &i)
{
	Scalar::printChar(os, i);
	Scalar::printInt(os, i);
	Scalar::printFloat(os, i);
	Scalar::printDouble(os, i);
	return (os);
}

/* ************************************************************************** */
/*                                 ACCES FONCTIONS                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                MEMBER FONCTIONS                            */
/* ************************************************************************** */

char const *Scalar::TooBigException::what() const throw()
{
	return ("Number too big");
}

char const *Scalar::TooSmallException::what() const throw()
{
	return ("Number too small");
}

char const *Scalar::NotANumberException::what() const throw()
{
	return ("Not a number");
}
