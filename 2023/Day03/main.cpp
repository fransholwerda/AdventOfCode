#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "EnginePart.hpp"

bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int count_digits(int n)
{
	int count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

std::vector<EnginePart> get_parts(std::vector<std::string> lines)
{
	std::vector<EnginePart> parts;
	int i = 0;
	while (i < lines.size())
	{
		int j = 0;
		while (j < lines[i].size())
		{
			if (is_digit(lines[i][j]))
			{
				int value = atoi(&lines[i][j]);
				int length = count_digits(value);
				parts.push_back(EnginePart(value, j, i, length, false));
				j += length;
			}
			else
				j++;
		}
		i++;
	}
	return (parts);
}

bool check_for_adjacent_symbol(std::vector<std::string> lines, EnginePart part, std::map<std::string, std::vector<int>> &symbol_adjacencies)
{
	int i = part.getY();
	if (i > 0)
		i--;
	while (i <= part.getY() + 1 && i < lines.size())
	{
		int j = part.getX();
		if (j > 0)
			j--;
		while (j < part.getX() + part.getLength() + 1 && j < lines[i].size())
		{
			if (lines[i][j] != '.' && !is_digit(lines[i][j]))
			{
				std::string coordinates = std::to_string(i) + "," + std::to_string(j);
				if (symbol_adjacencies.find(coordinates) == symbol_adjacencies.end())
				{
					symbol_adjacencies[coordinates] = std::vector<int>();
					symbol_adjacencies[coordinates].push_back(part.getValue());
				}
				else
				{
					for (int value : symbol_adjacencies[coordinates])
					{
						if (value == part.getValue())
							return (false);
					}
					symbol_adjacencies[coordinates].push_back(part.getValue());
				}
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
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

	std::vector<EnginePart> parts = get_parts(lines);

	int answer_part_one = 0;
	std::map<std::string, std::vector<int>> symbol_adjacencies;
	for (EnginePart part : parts)
	{
		if (check_for_adjacent_symbol(lines, part, symbol_adjacencies))
			answer_part_one += part.getValue();
	}

	std::cout << "Part one: " << answer_part_one << std::endl;

	int answer_part_two = 0;
	for (auto const &pair : symbol_adjacencies)
	{
		int gear_ratio = 0;
		for (int value : pair.second)
		{
			if (gear_ratio == 0 && value != pair.second.back())
				gear_ratio = value;
			else
				gear_ratio *= value;
		}
		answer_part_two += gear_ratio;
	}

	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
