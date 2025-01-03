#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

	long long answer_part_one = 0;
	std::vector<long long> numbers = split_longlong(lines[0], ",");
	numbers[1] = 12;
	numbers[2] = 2;
	size_t i = 0;
	while (i < numbers.size())
	{
		if (numbers[i] == 1)
			numbers[numbers[i+3]] = numbers[numbers[i+1]] + numbers[numbers[i+2]];
		else if (numbers[i] == 2)
			numbers[numbers[i+3]] = numbers[numbers[i+1]] * numbers[numbers[i+2]];
		else if (numbers[i] == 99)
			break;
		i += 4;
	}
	for (long long number : numbers)
		std::cout << number << ",";
	std::cout << std::endl;
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = 0;
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
