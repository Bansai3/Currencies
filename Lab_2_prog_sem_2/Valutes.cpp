#include "Valutes.h"
#include<iostream>
#include<string>

void Valutes::add_valute(std::string new_valute, double value_of_valute)
{
	valute_and_values[new_valute] = value_of_valute;
}

void Valutes::get_valutes()
{
	std::map<std::string, double>::iterator iter= valute_and_values.begin();
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
	std::map<std::string, double>::iterator iter = valute_and_values.begin();
	if (valute_and_values.size() % 2 == 0)
	{
		advance(iter, (valute_and_values.size() / 2) - 1);
		double first_med_number = iter->second;
		advance(iter, 1);
		return (first_med_number + iter->second) / 2;
	}
	else
	{
		advance(iter, (valute_and_values.size() / 2));
		return iter->second;
	}
}

