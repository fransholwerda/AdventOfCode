#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

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
	std::vector<long long> left;
	std::vector<long long> right;
	long long answer = 0;

	for (std::string line : lines)
	{
		std::vector<std::string> values = split(line, "   ");
		left.push_back(std::stoll(values[0]));
		right.push_back(std::stoll(values[1]));
	}

	std::sort(left.begin(), left.end(), std::greater<long long>());
	std::sort(right.begin(), right.end(), std::greater<long long>());
	std::vector<long long>::iterator it_left = left.begin();
	std::vector<long long>::iterator it_right = right.begin();
	while (it_left != left.end())
	{
		answer += abs(*it_left - *it_right);
		it_left++;
		it_right++;
	}
	return (answer);
}

long long part_two(std::vector<std::string> lines)
{
	std::vector<long long> left;
	std::vector<long long> right;
	long long answer = 0;

	for (std::string line : lines)
	{
		std::vector<std::string> values = split(line, "   ");
		left.push_back(std::stoll(values[0]));
		right.push_back(std::stoll(values[1]));
	}

	for (int value : left)
		answer += (value * std::count(right.begin(), right.end(), value));

	return (answer);
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
