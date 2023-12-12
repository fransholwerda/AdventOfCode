#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
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

long long get_next_iteration(std::vector<long long> data, bool first)
{
	std::vector<long long> differences;
	size_t i = 0;
	while (i < data.size() - 1)
	{
		differences.push_back(data[i + 1] - data[i]);
		i++;
	}
	bool is_zero = true;
	for (long long difference : differences)
	{
		if (difference != 0)
		{
			is_zero = false;
			break;
		}
	}
	if (is_zero)
		return (0);
	else if (first)
		return (differences[differences.size() - 1] + get_next_iteration(differences, true));
	else
		return (differences[0] - get_next_iteration(differences, false));
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
	{
		std::vector<long long> data = split_longlong(line, " ");
		long long next = get_next_iteration(data, true) + data[data.size() - 1];
		answer_part_one += next;
	}
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = 0;
	for (std::string line : lines)
	{
		std::vector<long long> data = split_longlong(line, " ");
		long long prev = data[0] - get_next_iteration(data, false);
		answer_part_two += prev;
	}
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
