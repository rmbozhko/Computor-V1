#include "Computor.hpp"

int main(int argc, char const *argv[])
{
	using namespace Computor;
	if (argc == 2)
	{
		if (std::strlen(argv[1]) > 0)
		{
			std::string		eq(argv[1]);

			eq.erase(remove_if(eq.begin(), eq.end(), isspace), eq.end());
			std::replace(eq.begin(), eq.end(), '=', ' ');

			std::vector<std::string> v;
			std::stringstream ss(eq);
			std::string temp;
			while (ss >> temp)
			    v.push_back(temp);
			if (v.size() == 2)
			{
				try
				{
					std::vector<Unknown> left = ParseEquation(v[0]);
					std::vector<Unknown> right = ParseEquation(v[1]);
					for (size_t i = 0; i <= MAX_POLYNOMIAL_DEGREE; ++i)
						if (right.size())
							SimplifyEquation(left, right, i);
					PrintSimplifiedEquation(left);
					switch (FindUknownFactWithMaxPolynDegree(left))
					{
						case 2:
							CalcEquation::HandleQuadraticEquation(left);
							break ;
						case 1:
							CalcEquation::HandleSimpleEquation(left);
							break ;
						case 0:
							CalcEquation::HandleEquality(left);
							break ;
						default:
							std::cout << "No equation found" << std::endl;
					}
				}
				catch (std::string msg)
				{
					std::cerr << msg << std::endl;
				}
			}
			else
				std::cerr << "Wrong format of equation" << std::endl;
		}
		else
			std::cerr << "Empty equation argument" << std::endl;
	}
	else
		std::cerr << "Wrong number of command line arguments" << std::endl;
	return 0;
}