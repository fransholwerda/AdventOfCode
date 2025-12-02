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

long long part_one(std::vector<std::string> lines)
{
	long long result = 0;
	std::vector<std::string> ranges;

	ranges = split(lines[0], ",");
	for (std::string range : ranges)
	{
		std::vector<std::string> bounds = split(range, "-");
		long long lower = std::stoll(bounds[0]);
		long long upper = std::stoll(bounds[1]);

		for (long long i = lower; i <= upper; i++)
		{
			std::string str_i = std::to_string(i);
			std::string first_half = str_i.substr(0, str_i.length() / 2);
			std::string second_half = str_i.substr(str_i.length() / 2, str_i.length());

			if (first_half == second_half)
			{
				result += i;
			}
		}
	}

	return (result);
}

bool check_if_repeating_pattern(std::string str)
{
	size_t len = str.length();
	for (size_t i = 1; i <= len / 2; i++)
	{
		if (len % i == 0)
		{
			std::string pattern = str.substr(0, i);
			std::string constructed;

			for (size_t j = 0; j < len / i; j++)
			{
				constructed += pattern;
			}
			if (constructed == str)
			{
				return (true);
			}
		}
	}
	return (false);
}

long long part_two(std::vector<std::string> lines)
{
	long long result = 0;
	std::vector<std::string> ranges;

	ranges = split(lines[0], ",");
	for (std::string range : ranges)
	{
		std::vector<std::string> bounds = split(range, "-");
		long long lower = std::stoll(bounds[0]);
		long long upper = std::stoll(bounds[1]);

		for (long long i = lower; i <= upper; i++)
		{
			std::string str_i = std::to_string(i);
			if (check_if_repeating_pattern(str_i))
			{
				result += i;
			}
		}
	}

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

	long long answer_part_one = part_one(lines);
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = part_two(lines);
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
