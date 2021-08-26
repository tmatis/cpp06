#ifndef SCALAR_HPP

# define SCALAR_HPP

# include <iostream>

class Scalar
{
	private:
		double _value;
	public:
		class TooBigException : public std::exception
		{
			char const *what() const throw();
		};
		class TooSmallException : public std::exception
		{
			char const *what() const throw();
		};
		class NotANumberException : public std::exception
		{
			char const *what() const throw();
		};
		static void	printChar(std::ostream &os, const Scalar &i);
		static void	printInt(std::ostream &os, const Scalar &i);
		static void	printFloat(std::ostream &os, const Scalar &i);
		static void	printDouble(std::ostream &os, const Scalar &i);
					Scalar(std::string const & num);
					Scalar(const Scalar &src);
					Scalar(void);
					~Scalar();
				operator float(void) const;
				operator double(void) const;
				operator int(void) const;
				operator char(void) const;	
		Scalar	&operator=(const Scalar &right);
};

std::ostream		&operator<<(std::ostream &os, const Scalar &i);

#endif // [SCALAR_HPP]
