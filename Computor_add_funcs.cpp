#include "Computor.hpp"

namespace Computor
{
	std::vector<Unknown>	ParseEquation(std::string& eq)
	{
		std::vector<Unknown> 	res;
		std::smatch				m;
		size_t					counter = 0;

		std::cout << eq << "|" << std::endl;
		
		if (std::regex_match(eq, m, std::regex("[+-]?[0-9]+([.][0-9]+)?[*][X][^][0]"
												"([+-][0-9]+([.][0-9]+)?[*][X][^][1])?"
												"([+-][0-9]+([.][0-9]+)?[*][X][^][2])?")))
		{
		    std::regex words_regex("[+-]?[0-9]+([.][0-9]+)?");
			auto start = std::sregex_iterator(eq.begin(), eq.end(), words_regex);
			auto end = std::sregex_iterator();
			for (std::sregex_iterator i = start; i != end; ++i, ++counter)
			{
		        if (counter == 0 || (counter % 2) == 0)
		        {
					std::cout << counter << "-th digit: " << stod((*i).str()) << std::endl;
		        	res.push_back(Unknown(stod((*i).str()), counter));
		        }
		        // std::smatch match = *i;                                             
		        // std::string match_str = match.str(); 
		        // std::cout << "|" << match_str << '\n';
    		}
		}
		else
			throw std::string("Undefined character found in passed equation");
		return (res);
	}

	int			FindUknownFactByPolynDegree(std::vector<Unknown>& v, const size_t polynomial_degree)
	{
		int		pos;

		pos = -1;
		for (int i = 0; i < v.size(); ++i)
			if (v[i].GetPolynDegree() == polynomial_degree)
				pos = i;
		return (pos);
	}

	int			FindUknownFactWithMaxPolynDegree(std::vector<Unknown>& v)
	{
		int		max_degree;

		max_degree = -1;
		for (int i = 0; i < v.size(); ++i)
			if (v[i].GetPolynDegree() > max_degree)
				max_degree = v[i].GetPolynDegree();
		return (max_degree);
	}

	void		SimplifyEquation(std::vector<Unknown>& left, std::vector<Unknown>& right, const size_t polynomial_degree)
	{
		int		r_pos = FindUknownFactByPolynDegree(right, polynomial_degree);
		if (r_pos != -1)
		{
			Unknown		r_elem = right[r_pos];
			int l_pos = FindUknownFactByPolynDegree(left, polynomial_degree);
			if (r_elem.GetNumber() != 0.0)
					r_elem.SetNumber(-r_elem.GetNumber()); // handle max int
			if (l_pos != -1)
			{
				Unknown		l_elem = left[l_pos];
				l_elem.SetNumber(l_elem.GetNumber() + r_elem.GetNumber());
			}
			else
				left.push_back(r_elem);
			right.erase(right.begin() + r_pos);
		}
	}

	void		PrintResults(const std::string msg, const size_t polynomial_degree)
	{
		std::cout << "Polynomial degree: " << polynomial_degree << std::endl;
		std::cout << "The solution is:" << std::endl;
		if (msg.size())
			std::cout << msg << std::endl;
	}

	void		PrintResults(const double res, const size_t polynomial_degree)
	{
		std::cout << "Polynomial degree: " << polynomial_degree << std::endl;
		std::cout << "The solution is:" << std::endl;
		std::cout << res << std::endl;
	}

	void		PrintResults(const std::pair<double, double> res, const size_t polynomial_degree)
	{
		std::cout << "Polynomial degree: " << polynomial_degree << std::endl;
		std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
		std::cout << res.first << std::endl;
		std::cout << res.second << std::endl;
	}

	void		PrintSimplifiedEquation(std::vector<Unknown>& v)
	{
		if (v.size() != MAX_POLYNOMIAL_DEGREE)
			throw std::string("Wrong simplified equation");
		for (int i = 0; i < v.size(); ++i)
		{
			Unknown& temp = v[FindUknownFactByPolynDegree(v, i)];
			if (i != 0 && temp.GetNumber() < 0.0)
				std::cout << " - " << -temp.GetNumber();
			else if (i != 0 && temp.GetNumber() >= 0.0)
				std::cout << " + " << temp.GetNumber();
			else
				std::cout << temp.GetNumber();
			std::cout << " * X^" << temp.GetPolynDegree();
		}
		std::cout << " = 0" << std::endl;
	}
}
