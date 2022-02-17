#include "Valutes.h"
#include<iostream>
#include<string>
#include <algorithm>

void Valutes::add_valute(std::string new_valute, double value_of_valute)
{
	valute_and_values[new_valute] = value_of_valute;
}

void Valutes::get_valutes()
{
	std::map<std::string, double>::iterator iter = valute_and_values.begin();
	for (int i = 0; i < valute_and_values.size(); i++)
	{
		std::cout << iter->first << "  =  " << iter->second << std::endl;
		iter++;
	}
}

double Valutes::get_average()
{
	double sum = 0;
	std::map<std::string, double>::iterator iter = valute_and_values.begin();
	for (int i = 0; i < valute_and_values.size(); i++)
	{
		sum += iter->second;
		iter++;
	}
	return sum / valute_and_values.size();
}

double Valutes::get_median()
{
	std::vector<double> mass_of_values;
	std::map<std::string, double>::iterator it = valute_and_values.begin();
	for (int i = 0; i < valute_and_values.size(); i++)
	{
		mass_of_values.push_back(it->second);
		it++;
	}
	sort(mass_of_values.begin(), mass_of_values.end());
	if (mass_of_values.size() % 2 == 0)
	{
		double first_med_number = mass_of_values[mass_of_values.size() / 2 - 1];
		double second_med_number = mass_of_values[mass_of_values.size() / 2];
		return (first_med_number + second_med_number) / 2;
	}
	else
	{
		return mass_of_values[mass_of_values.size() / 2];
	}
}

void Valutes::get_sort_values()
{
	std::vector<double> mass_of_values;
	std::map<std::string, double>::iterator it = valute_and_values.begin();
	for (int i = 0; i < valute_and_values.size(); i++)
	{
		mass_of_values.push_back(it->second);
		it++;
	}
	sort(mass_of_values.begin(), mass_of_values.end());
	for (auto i : mass_of_values)
	{
		std::cout << i << " ";
	}
}

