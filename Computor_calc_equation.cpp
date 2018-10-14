#include "Computor.hpp"

namespace Computor
{
	namespace CalcEquation
	{
		std::pair<std::string, std::string>		CalcDiscriminant(double a, double b, double c)
		{
			double	D, x1, x2;
			auto sqrt = [&](const double number)
			{
				const double ACCURACY = 0.001;
				double lower, upper, guess;

				if (number < 1)
				{
					lower = number;
					upper = 1;
				}
				else
				{
					lower = 1;
					upper = number;
				}

				while ((upper - lower) > ACCURACY)
				{
					guess = (lower + upper) / 2;
					if (guess * guess > number)
						upper = guess;
					else
						lower = guess; 
				}
				return (lower + upper) / 2;
			};

			D = (b * b) - (4 * a * c);
			
			if (D > 0.0)
			{
				std::cout << "Discriminant is greater than zero" << std::endl;
				x1 = (-b + sqrt(D)) / (2 * a);
				x2 = (-b - sqrt(D)) / (2 * a);
			}
			else if (D == 0.0)
			{
				std::cout << "Discriminant is equal to zero" << std::endl;
				x1 = x2 = (-b + sqrt(D)) / (2 * a);
			}
			else
			{
				double x1 = -b / (2 * a);
		        double x2 = sqrt(-D) / ( 2 * a);
		        std::cout << "Discriminant is less than zero" << std::endl;
		        return (std::make_pair(std::to_string(x1) + " + " + std::to_string(x2) + "i",
		        						std::to_string(x1) + " - " + std::to_string(x2) + "i"));
		    }
			
			return (std::make_pair(std::to_string(x1), std::to_string(x2)));
		}

		void		HandleQuadraticEquation(std::vector<Unknown>& v)
		{
			Unknown&	a = v[FindUknownFactByPolynDegree(v, 2)];
			Unknown&	b = v[FindUknownFactByPolynDegree(v, 1)];
			Unknown&	c = v[FindUknownFactByPolynDegree(v, 0)];
			auto		res = CalcDiscriminant(a.GetNumber(), b.GetNumber(), c.GetNumber());
			GenerateGraph(v);
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
			GenerateGraph(v);
			PrintResults(res, 1);
		}

		void		HandleEquality(std::vector<Unknown>& v)
		{
			Unknown&	c = v[FindUknownFactByPolynDegree(v, 0)];

			if (c.GetNumber() == 0.0)
			{
				GenerateGraph(v);
				PrintResults("The equation has no indeterminates variable - nothing to solve", 0);
			}
			else
				throw std::string("Nothing to solve - empty polynomial equation");
		}
	}
}