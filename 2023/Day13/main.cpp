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

std::string vert_string(std::vector<std::string> vec, size_t col)
{
	std::string result;
	for (size_t i = 0; i < vec.size(); i++)
		result.push_back(vec[i][col]);
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

	std::vector<std::vector<std::string>> patterns;
	size_t i = 0;
	size_t start = 0;
	while (i < lines.size())
	{
		if (i == lines.size() - 1 || lines[i] == "")
		{
			std::vector<std::string> pattern;
			while (start < i)
			{
				pattern.push_back(lines[start]);
				start++;
			}
			patterns.push_back(pattern);
			start++;
		}
		i++;
	}

	long long answer_part_one = 0;
	for (std::vector<std::string> pattern : patterns)
	{
		i = 1;
		bool mirror = false;
		while (i < pattern.size() - 2)
		{
			if (pattern[i] == pattern[i+1])
			{
				size_t left = -1;
				size_t right = 2;
				mirror = true;
				while (i + left >= 0 && i + right < pattern.size())
				{
					if (pattern[i+left] != pattern[i+right])
					{
						mirror = false;
						break;
					}
					left--;
					right++;
				}
				if (mirror)
					answer_part_one += (i+1) * 100;
			}
			if (mirror)
				break;
			i++;
		}
		if (mirror)
			continue;
		i = 1;
		while (i < pattern[0].size() - 2)
		{
			if (vert_string(pattern, i) == vert_string(pattern, i+1))
			{
				size_t left = -1;
				size_t right = 2;
				mirror = true;
				while (i + left >= 0 && i + right < pattern[0].size())
				{
					if (vert_string(pattern, i+left) != vert_string(pattern, i+right))
					{
						mirror = false;
						break;
					}
					left--;
					right++;
				}
				if (mirror)
					answer_part_one += (i+1);
			}
			if (mirror)
				break;
			i++;
		}
	}
	std::cout << "Part one: " << answer_part_one << std::endl;

	long long answer_part_two = 0;
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
