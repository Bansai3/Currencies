#pragma once
#include<vector>
#include<map>

class Valutes
{
	std::map<std::string, double> valute_and_values;
public:
	void add_valute(std::string new_valute, double value_of_valute);
	void get_valutes();
	double get_average();
	double get_median();
	void get_sort_values();
};

