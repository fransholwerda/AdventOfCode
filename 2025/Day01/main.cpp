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

int part_one(const std::vector<std::string>& lines)
{

	int dial_hit_zero = 0;
	int dial_pos = 50;

	for (const std::string& line : lines)
	{
		if (line.empty())
		{
			continue;
		}

		int distance = std::stoi(line.substr(1));
		if (line[0] == 'L')
		{
			dial_pos = (dial_pos - distance + 100) % 100;
		}
		else if (line[0] == 'R')
		{
			dial_pos = (dial_pos + distance) % 100;
		}
		if (dial_pos == 0)
		{
			dial_hit_zero++;
		}
	}

	return dial_hit_zero;
}

int part_two(const std::vector<std::string>& lines)
{

	int dial_hit_zero = 0;
	int dial_pos = 50;

	for (const std::string& line : lines)
	{
		if (line.empty())
		{
			continue;
		}
		int distance = std::stoi(line.substr(1));

		if (distance > 100)
		{
			dial_hit_zero += (distance / 100);
			distance = distance % 100;
		}

		if (line[0] == 'L')
		{
			int dial_is_zero = 0;
			if (dial_pos == 0)
			{
				dial_is_zero = 1;
			}

			dial_pos = (dial_pos - distance);
			if (dial_pos <= 0)
			{
				dial_hit_zero += 1 - dial_is_zero;
			}
			dial_pos = (dial_pos + 100) % 100;
		}
		else if (line[0] == 'R')
		{
			dial_pos = (dial_pos + distance);
			if (dial_pos >= 100)
			{
				dial_hit_zero++;
			}
			dial_pos = (dial_pos) % 100;
		}
	}

	return dial_hit_zero;
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
