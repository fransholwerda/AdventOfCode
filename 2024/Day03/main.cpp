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

bool is_valid_expr(std::string line, size_t i)
{
	size_t start_i = i;
	while(line[i] >= '0' && line[i] <= '9')
		++i;
	if (i <= start_i || line[i] != ',')
		return (false);
	++i;
	start_i = i;
	while(line[i] >= '0' && line[i] <= '9')
		++i;
	if (i <= start_i || line[i] != ')')
		return (false);
	return (true);
}

long long mul(std::string expr, size_t i)
{
	long long left = std::stoll(&expr[i]);
	long long right = std::stoll(&expr[expr.find(",", i) + 1]);
	return (left * right);
}

long long part_one(std::string file)
{
	long long sum = 0;
	size_t i = 0;
	while (i < file.size())
	{
		i = file.find("mul(", i);
		if (i == file.npos)
			break;
		if (is_valid_expr(file, i + 4))
			sum += mul(file, i + 4);
		++i;
	}
	return (sum);
}

long long part_two(std::string file)
{
	while (true)
	{
		size_t start = file.find("don't()");
		if (start == file.npos)
			break;
		size_t end = file.find("do()", start);
		file.erase(file.begin() + start, file.begin() + end);
	}
	return (part_one(file));
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
	std::string file((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	infile.close();

	long long answer_part_one = part_one(file);
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = part_two(file);
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
