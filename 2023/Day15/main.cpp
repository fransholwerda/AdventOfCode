#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>

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

long long get_hash(std::string data)
{
	long long data_score = 0;
	for (char c : data)
	{
		data_score += static_cast<long long>(c);
		data_score *= 17;
		data_score %= 256;
	}
	return (data_score);
}

int find_index(std::vector<std::map<std::string, long long>>& vec, std::string target)
{
	int i = 0;
	vec.er
	while (i < vec.size())
	{
		if (vec[i].find(target) != vec[i].end())
			return (i);
		i++;
	}
	return (-1);
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
	std::map<long long, std::vector<std::map<std::string, long long>>> boxes;
	for (std::string data: split(lines[0], ","))
	{
		answer_part_one += get_hash(data);

		if (data.find('=') != data.npos)
		{
			std::vector<std::string> split_data = split(data, "=");
			long long key = get_hash(split_data[0]);
			if (boxes.find(key) == boxes.end())
			{
				std::map<std::string, long long> temp;
				temp[split_data[0]] = atoll(split_data[1].c_str());
				boxes[key].push_back(temp);
			}
			else
			{
				std::vector<std::map<std::string, long long>> temp_vec;
				std::map<std::string, long long> temp_map;
				boxes[key][split_data[0]] = atoll(split_data[1].c_str());
				boxes[key] = temp;
			}
		}
		else
		{
			std::string rem = data.substr(data.length() - 1);
			long long key = get_hash(rem);
			boxes[key].erase(rem);
		}
	}
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = 0;
	for (std::map<long long, std::map<std::string, long long>>::iterator it = boxes.begin(); it != boxes.end(); it++)
	{
		for (std::map<std::string, long long>::iterator it2 = boxes[it->first].begin(); it2 != boxes[it->first].end(); it2++)
		{
			long long score = (it->first + 1); //FINISH THIS
		}
	}
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
