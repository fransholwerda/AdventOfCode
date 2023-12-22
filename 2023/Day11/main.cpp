#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <math.h>
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

bool empty_column(std::vector<std::string> data, size_t x)
{
	for (size_t y = 0; y < data.size(); y++)
	{
		if (data[y][x] != '.')
			return (false);
	}
	return (true);
}

bool empty_row(std::string data)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i] != '.')
			return (false);
	}
	return (true);
}

std::string make_string(char c, size_t count)
{
	std::string result;
	for (size_t i = 0; i < count; i++)
		result.push_back(c);
	return (result);
}

int empty_space_horizontal(std::vector<std::string> data, int start, int end)
{
	int count = 0;
	for (size_t y = static_cast<size_t>(start); static_cast<size_t>(y) < end; y++)
	{
		if (data[y][0] == '-')
			count++;
	}
	return (count);
}

int empty_space_vertical(std::vector<std::string> data, int start, int end)
{
	int count = 0;
	for (size_t x = static_cast<size_t>(start); static_cast<size_t>(x) < end; x++)
	{
		if (data[0][x] == '-')
			count++;
	}
	return (count);
}

int main(void)
{
	std::ifstream infile;
	infile.open("test_input.txt");
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
	std::vector<std::string> data;
	for (std::string line : lines)
	{
		if (empty_row(line))
			data.push_back(make_string('-', line.size()));
		else
		{
			size_t x = 0;
			std::string row;
			while (x < line.size())
			{
				if (empty_column(lines, x))
					row.append("-");
				else
					row.append(line.substr(x, 1));
				x++;
			}
			data.push_back(row);
		}
	}
	for (std::string blah : data)
		std::cout << blah << std::endl;
	std::map<size_t, std::vector<int>> galaxies;
	size_t galaxy_count = 0;
	int y = 0;
	while (y < static_cast<int>(data.size()))
	{
		int x = 0;
		while (x < static_cast<int>(data[y].size()))
		{
			if (data[y][x] == '#')
				galaxies[++galaxy_count] = {x, y};
			x++;
		}
		y++;
	}
	for (size_t i = 1; i < galaxy_count; i++)
	{
		for (size_t j = i + 1; j <= galaxy_count; j++)
		{
			answer_part_one += abs(galaxies[j][0] - galaxies[i][0]) + abs(galaxies[j][1] - galaxies[i][1]);
		}
	}
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = 0;
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
