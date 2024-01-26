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

void move_vert(std::vector<std::string>& data, size_t x, size_t y, int dir)
{
	size_t temp_y = y;

	while (((dir == -1 && temp_y > 0) || (dir == 1 && temp_y < data.size() - 1)) &&
				data[temp_y + dir][x] == '.')
	{
		temp_y += dir;
	}
	data[y][x] = '.';
	data[temp_y][x] = 'O';
}

void move_hori(std::vector<std::string>& data, size_t x, size_t y, int dir)
{
	size_t temp_x = x;

	while (((dir == -1 && temp_x > 0) || (dir == 1 && temp_x < data[0].length() - 1)) &&
			data[y][temp_x + dir] == '.')
	{
		temp_x += dir;
	}
	data[y][x] = '.';
	data[y][temp_x] = 'O';
}

void move_north(std::vector<std::string>& data)
{
	for (size_t y = 0; y < data.size(); y++)
	{
		for (size_t x = 0; x < data[0].length(); x++)
		{
			if (data[y][x] == 'O')
				move_vert(data, x, y, -1);
		}
	}
}

void move_west(std::vector<std::string>& data)
{
	for (size_t y = 0; y < data.size(); y++)
	{
		for (size_t x = 0; x < data[0].length(); x++)
		{
			if (data[y][x] == 'O')
				move_hori(data, x, y, -1);
		}
	}
}

void move_south(std::vector<std::string>& data)
{
	for (size_t y = data.size(); y > 0; y--)
	{
		for (size_t x = data[0].length(); x > 0; x--)
		{
			if (data[y-1][x-1] == 'O')
				move_vert(data, x-1, y-1, 1);
		}
	}
}

void move_east(std::vector<std::string>& data)
{
	for (size_t y = data.size(); y > 0; y--)
	{
		for (size_t x = data[0].length(); x > 0; x--)
		{
			if (data[y-1][x-1] == 'O')
				move_hori(data, x-1, y-1, 1);
		}
	}
}

void spin_cycle(std::map<std::vector<std::string>, std::vector<std::string>>& cache, std::vector<std::string>& data)
{
	if (cache.find(data) != cache.end())
	{
		data = cache[data];
		return ;
	}
	std::vector<std::string> temp(data);
	move_north(data);
	move_west(data);
	move_south(data);
	move_east(data);
	cache[temp] = data;
}

long long score(std::vector<std::string>& data)
{
	long long score = 0;

	for (size_t y = 0; y < data.size(); y++)
	{
		for (size_t x = 0; x < data[y].length(); x++)
		{
			if (data[y][x] == 'O')
				score += data.size() - y;
		}
	}
	return (score);
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

	std::vector<std::string> data(lines);
	move_north(data);
	long long answer_part_one = score(data);
	std::cout << "Part one: " << answer_part_one << std::endl;

	std::map<std::vector<std::string>, std::vector<std::string>> cache;
	for (size_t i = 0; i < 1000; i++)
		spin_cycle(cache, lines);
	long long answer_part_two = score(lines);
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
