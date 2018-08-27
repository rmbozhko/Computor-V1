#include "Computor.hpp"

namespace Computor
{
	namespace CalcEquation
	{
		std::pair<double, double>		CalcDiscriminant(int a, int b, int c)
		{
			double	D = std::sqrt((b * b) - (4 * a * c));
			double	x1 = (-b + D) / (2 * a);
			double	x2 = (-b - D) / (2 * a);
			return (std::make_pair<double, double>(x1, x2));
		}

		void		HandleQuadraticEquation(std::vector<Unknown>& v)
		{
			Unknown&	a = FindUknownFactByPolynDegree(v, 2);
			Unknown&	b = FindUknownFactByPolynDegree(v, 1);
			Unknown&	c = FindUknownFactByPolynDegree(v, 0);
			auto		res = CalcDiscriminant(a.GetNumber(), b.GetNumber(), c.GetNumber());
			PrintResults(res, 2);
		}

		void		HandleSimpleEquation(std::vector<Unknown>& v)
		{
			double		res;
			Unknown&	b = FindUknownFactByPolynDegree(v, 1);
			Unknown&	c = FindUknownFactByPolynDegree(v, 0);

			if (c.GetNumber() != 0)
			{
				c.SetNumber(-c.GetNumber());
				res = c.GetNumber() / b.GetNumber();
			}
			else
				res = 0.0;
			PrintResults(res, 1);
		}

		void		HandleEquality(std::vector<Unknown>& v)
		{
			Unknown&	c = FindUknownFactByPolynDegree(v, 0);
			double		res;

			if (c.GetNumber() == 0)
				PrintResults("All real numbers", 0);
			else
				throw std::string("Equation is unsolvable");
		}
	}
}