#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>

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

std::vector<size_t> get_start_pos(std::vector<std::string> map)
{
	std::vector<size_t> start_pos;

	size_t i = 0;
	while (i < map.size())
	{
		size_t j = 0;
		while (j < map[0].size())
		{
			if (map[i][j] == '^')
				break ;
			++j;
		}
		if (map[i][j] == '^')
		{
			start_pos.push_back(i);
			start_pos.push_back(j);
			break ;
		}
		++i;
	}

	return (start_pos);
}

long long count_path(std::vector<std::string> map)
{
	long long count = 0;
	for (std::string line : map)
	{
		for (char c : line)
		{
			if (c == 'X')
				++count;
		}
	}
	return (count);
}

long long part_one(std::vector<std::string> map)
{
	std::vector<size_t> pos = get_start_pos(map);
	std::map<char, std::tuple<int, int, char>> dirMap = {
		{'N', {-1, 0, 'E'}},
		{'E', {0, 1, 'S'}},
		{'S', {1, 0, 'W'}},
		{'W', {0, -1, 'N'}}
	};
	char dir = 'N';

	while (true)
	{
		map[pos[0]][pos[1]] = 'X';
		pos[0] += std::get<0>(dirMap[dir]);
		pos[1] += std::get<1>(dirMap[dir]);
		if (!(pos[0] >= 0 && pos[0] < map.size() &&
			pos[1] >= 0 && pos[1] < map[0].size()))
			break;
		else if (map[pos[0]][pos[1]] == '#')
		{
			pos[0] -= std::get<0>(dirMap[dir]);
			pos[1] -= std::get<1>(dirMap[dir]);
			dir = std::get<2>(dirMap[dir]);
		}
	}
	return (count_path(map));
}

bool path_loops(std::vector<std::string> map, std::vector<size_t> pos)
{
	std::map<char, std::tuple<int, int, char>> dirMap = {
		{'N', {-1, 0, 'E'}},
		{'E', {0, 1, 'S'}},
		{'S', {1, 0, 'W'}},
		{'W', {0, -1, 'N'}}
	};
	char dir = 'N';
	std::set<std::tuple<int, int, char>> visited;

	while (true)
	{
		if (visited.find({pos[0], pos[1], dir}) != visited.end())
			return (true);
		visited.insert({pos[0], pos[1], dir});
		pos[0] += std::get<0>(dirMap[dir]);
		pos[1] += std::get<1>(dirMap[dir]);
		if (!(pos[0] >= 0 && pos[0] < map.size() &&
			pos[1] >= 0 && pos[1] < map[0].size()))
			break;
		else if (map[pos[0]][pos[1]] == '#')
		{
			pos[0] -= std::get<0>(dirMap[dir]);
			pos[1] -= std::get<1>(dirMap[dir]);
			dir = std::get<2>(dirMap[dir]);
		}
	}
	return (false);
}

// YES IT'S BRUTEFORCE, SUE ME D:
long long part_two(std::vector<std::string> map)
{
	long long loop_obstructions = 0;
	std::vector<size_t> pos = get_start_pos(map);
	size_t i = 0;
	while (i < map.size())
	{
		size_t j = 0;
		while (j < map[i].size())
		{
			if (map[i][j] == '#')
			{
				++j;
				continue;
			}
			map[i][j] = '#';
			if (path_loops(map, pos))
				++loop_obstructions;
			map[i][j] = '.';
			++j;
		}
		++i;
	}
	return (loop_obstructions);
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
