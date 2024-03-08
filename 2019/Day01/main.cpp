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

long long calculate_fuel(long long data)
{
	data /= 3;
	data -= 2;
	return (data);
}

long long recursive_calculate_fuel(long long data)
{
	data /= 3;
	data -= 2;
	if (data <= 0)
		return (0);
	else
		return (data + recursive_calculate_fuel(data));
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
	for (std::string line : lines)
		answer_part_one += calculate_fuel(std::stoll(line));
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = 0;
	for (std::string line : lines)
		answer_part_two += recursive_calculate_fuel(std::stoll(line));
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
