#ifndef COMPUTOR_HPP
# define COMPUTOR_HPP

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Unknown.hpp"

# define MAX_POLYNOMIAL_DEGREE 2

std::vector<Unknown>	ParseEquation(std::vector<std::string>& v);
int			FindUknownFactByPolynDegree(std::vector<Unknown>& v, const size_t polynomial_degree);
int			FindUknownFactWithMaxPolynDegree(std::vector<Unknown>& v);
void		SimplifyEquation(std::vector<Unknown>& left, std::vector<Unknown>& right, const size_t polynomial_degree);
void		PrintResults(const std::string msg, const size_t polynomial_degree);
void		PrintResults(const double res, const size_t polynomial_degree);
void		PrintResults(const std::pair<double, double> res, const size_t polynomial_degree);
void		PrintSimplifiedEquation(std::vector<Unknown>& v);

std::pair<double, double>		CalcDiscriminant(int a, int b, int c);
void		HandleQuadraticEquation(std::vector<Unknown>& v);
void		HandleSimpleEquation(std::vector<Unknown>& v);
void		HandleEquality(std::vector<Unknown>& v);

#endif