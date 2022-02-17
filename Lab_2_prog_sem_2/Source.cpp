#define CURL_STATICLIB
#include<ctime>
#include<iostream>
#include"Get_json.h"
#include<boost/property_tree/ptree.hpp>
#include<boost/property_tree/json_parser.hpp>
#include<nlohmann/json.hpp>
#include <SFML/Graphics.hpp>
#include"Valutes.h"
#include<conio.h>
#include<stdlib.h>

using json = nlohmann::json;


void get_field_from_json(std::string json, std::string field, std::string mass_of_keys, Valutes& valutes)
{
	std::string valute_name;
	double value;
	std::stringstream jsonEncoded(json);
	boost::property_tree::ptree root;
	boost::property_tree::read_json(jsonEncoded, root);
	valute_name = root.get_child(field).get_child(mass_of_keys).get <std::string>("Name");
	value = root.get_child(field).get_child(mass_of_keys).get <double>("Value");
	valutes.add_valute(valute_name, value);
} 

int time()
{
	clock_t start;
	clock_t end;
	start = clock();
	Sleep(10000);
	end = clock();
	return 0;
}

int main()
{
	std::vector<std::string> mass_of_keys = { "AUD","AZN","GBP","AMD","BYN","BGN","BRL","HUF","HKD","DKK","USD","EUR",
											  "INR","KZT","CAD","KGS","CNY","MDL","NOK","PLN","RON","XDR","SGD","TJS",
											  "TRY","TMT","UZS","UAH","CZK","SEK","CHF","ZAR","KRW","JPY" };
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);


	Client client;
	Valutes valutes;
	std::string str;
	json j;

	j = client.Get_response("");
	for (int i = 0; i < mass_of_keys.size(); i++)
	{
		get_field_from_json(j, "Valute", mass_of_keys[i], valutes);
	}

	do
	{
		valutes.get_valutes();
		time();
		system("cls");
		if (_kbhit())
			break;
	} while (1);

	valutes.get_sort_values();
	std::cout << std::endl;
	std:: cout << valutes.get_average();
	std::cout << std::endl;
	std:: cout << valutes.get_median();
	
	return 0;
}