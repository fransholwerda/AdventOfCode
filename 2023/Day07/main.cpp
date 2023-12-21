#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include "Hand.hpp"
#include "Stack.hpp"

std::vector<std::string> split(std::string str, std::string delim)
{
	std::vector<std::string> result;
	size_t pos = 0;
	while ((pos = str.find(delim)) != std::string::npos)
	{
		result.push_back(str.substr(0, pos));
		str.erase(0, pos + delim.length());
	}
	result.push_back(str);
	return (result);
}

std::vector<long long> split_longlong(std::string str, std::string delim)
{
	std::vector<long long> result;
	size_t pos = 0;
	while ((pos = str.find(delim)) != std::string::npos)
	{
		try
		{
			result.push_back(std::stoll(str.substr(0, pos)));
		}
		catch(const std::exception& e)
		{
		}
		str.erase(0, pos + delim.length());
	}
	result.push_back(std::stoll(str));
	return (result);
}

int main(void)
{
	std::ifstream infile;
	infile.open("input.txt");
	if (infile.fail())
	{
		std::cout << "Could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	std::vector<std::string> lines;
	while (!infile.eof())
	{
		std::string str;
		std::getline(infile, str);
		lines.push_back(str);
	}
	infile.close();

	std::vector<Hand> hands;
	for (size_t i = 0; i < lines.size(); i++)
	{
		std::vector<std::string> data = split(lines[i], " ");
		std::string cards = data[0];
		long long value = std::stoll(data[1]);
		Hand hand(cards, value);
		hands.push_back(hand);
	}
	Stack stack(hands);
	stack.divide_hands(false);
	stack.sort_stack(false);
	long long answer_part_one = stack.get_stack_score();
	std::cout << "Answer Part One = " << answer_part_one << std::endl;

	Stack stack_joker(hands);
	stack_joker.divide_hands(true);
	stack_joker.sort_stack(true);
	long long answer_part_two = stack_joker.get_stack_score();
	std::cout << "Answer Part Two = " << answer_part_two << std::endl;
	return (EXIT_SUCCESS);
}
