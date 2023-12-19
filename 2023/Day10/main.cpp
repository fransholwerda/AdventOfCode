#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#include "Map.hpp"

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

	Map map;
	map.fill_map(lines);
	long long answer_part_one = map.make_main_pipe(lines);
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = 0;
	long long x_size = static_cast<long long>(map.get_map()[0].size());
	long long y_size = static_cast<long long>(map.get_map().size());
	for (long long y = 0; y < y_size; y++)
	{
		for (long long x = 0; x < x_size; x++)
		{
			if (map.get_map()[y][x] != -2 || map.get_map()[y][x] != -3)
			{
				map.flood_fill(x, y, map.connected_to_edge(x, y, x_size, y_size));
				map.clear_visited();
			}
			if (map.get_map()[y][x] == -3)
			{
				long long xx = 0;
				size_t boundary_count = 0;
				while (x+xx < static_cast<long long>(map.get_map()[y].size()))
				{
					if (map.get_map()[y][x+xx] >= 0)
					{
						if(lines[y][x+xx] == 'F')
						{
							while(lines[y][x+xx+1] == '-')
								xx++;
							if (lines[y][x+xx+1] == 'J')
								xx++;
						}
						else if(lines[y][x+xx] == 'L')
						{
							while(lines[y][x+xx+1] == '-')
								xx++;
							if (lines[y][x+xx+1] == '7')
								xx++;
						}
						boundary_count++;
					}
					xx++;
				}
				if (boundary_count % 2 == 1)
					answer_part_two++;
			}
		}
	}
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
