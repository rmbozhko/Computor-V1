#ifndef UNKNOWN_HPP
# define UNKNOWN_HPP

class Unknown
{
	public:
		Unknown(size_t polynomial_degree, int number) : polynomial_degree_(polynomial_degree), number_(number) {};
		~Unknown();
		void	SetNumber(int number) { number_ = number; }
		int		GetNumber() const { return (number_); }
		size_t	GetPolynDegree() const { return (polynomial_degree_); }

	private:
		size_t	polynomial_degree_;
		int		number_;
};

#endif