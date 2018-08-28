#include "Computor.hpp"

namespace Computor
{
	namespace CalcEquation
	{
		std::pair<double, double>		CalcDiscriminant(double a, double b, double c)
		{
			double	D = (b * b) - (4 * a * c);
			if (D < 0.0)
				throw std::string("Discriminant is negative");
			double	x1 = (-b + std::sqrt(D)) / (2 * a);
			double	x2 = (-b - std::sqrt(D)) / (2 * a);
			return (std::make_pair(x1, x2));
		}

		void		HandleQuadraticEquation(std::vector<Unknown>& v)
		{
			Unknown&	a = v[FindUknownFactByPolynDegree(v, 2)];
			Unknown&	b = v[FindUknownFactByPolynDegree(v, 1)];
			Unknown&	c = v[FindUknownFactByPolynDegree(v, 0)];
			auto		res = CalcDiscriminant(a.GetNumber(), b.GetNumber(), c.GetNumber());
			PrintResults(res, 2);
		}

		void		HandleSimpleEquation(std::vector<Unknown>& v)
		{
			double		res;
			Unknown&	b = v[FindUknownFactByPolynDegree(v, 1)];
			Unknown&	c = v[FindUknownFactByPolynDegree(v, 0)];

			if (c.GetNumber() != 0.0)
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
			Unknown&	c = v[FindUknownFactByPolynDegree(v, 0)];

			if (c.GetNumber() == 0.0)
				PrintResults("The equation has no indeterminates variable - nothing to solve", 0);
			else
				throw std::string("Nothing to solve - empty polynomial equation");
		}
	}
}