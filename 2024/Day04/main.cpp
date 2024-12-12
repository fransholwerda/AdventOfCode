#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

long long count_xmas(std::vector<std::string> lines)
{
	long long xmas = 0;
	for (std::string line : lines)
	{
		size_t i = line.find("XMAS");
		while (i != std::string::npos)
		{
			++xmas;
			i = line.find("XMAS", i + 1);
		}
	}
	return (xmas);
}

void add_hor_lines(std::vector<std::string> lines, std::vector<std::string>& all_lines)
{
	for (std::string line : lines)
	{
		all_lines.push_back(line);
		std::string reversed = line;
		std::reverse(reversed.begin(), reversed.end());
		all_lines.push_back(reversed);
	}
}

void add_vert_lines(std::vector<std::string> lines, std::vector<std::string>& all_lines)
{
	size_t i = 0;
	while (i < lines[0].size())
	{
		size_t j = 0;
		std::string vert_down;
		while (j < lines.size())
		{
			vert_down.push_back(lines[j][i]);
			++j;
		}
		
		std::string vert_up = vert_down;
		std::reverse(vert_up.begin(), vert_up.end());

		all_lines.push_back(vert_down);
		all_lines.push_back(vert_up);
		++i;
	}
}

void add_diag_lines(std::vector<std::string> lines, std::vector<std::string>& all_lines)
{
	size_t i = 0;
	while (i < lines[0].size())
	{
		size_t j = i;
		size_t k = 0;
		std::string diag_se;
		while (j < lines[0].size() && k < lines.size())
		{
			diag_se.push_back(lines[k][j]);
			++j;
			++k;
		}
		std::string diag_nw = diag_se;
		std::reverse(diag_nw.begin(), diag_nw.end());

		all_lines.push_back(diag_se);
		all_lines.push_back(diag_nw);
		++i;
	}

	i = 1;
	while (i < lines.size())
	{
		size_t j = i;
		size_t k = 0;
		std::string diag_se;
		while (j < lines.size() && k < lines[0].size())
		{
			diag_se.push_back(lines[j][k]);
			++j;
			++k;
		}
		std::string diag_nw = diag_se;
		std::reverse(diag_nw.begin(), diag_nw.end());

		all_lines.push_back(diag_se);
		all_lines.push_back(diag_nw);
		++i;
	}

	i = lines[0].size() - 1;
	while (i >= 0 && i < lines[0].size())
	{
		size_t j = i;
		size_t k = 0;
		std::string diag_sw;
		while (j >= 0 && j < lines[0].size() && k < lines.size())
		{
			diag_sw.push_back(lines[k][j]);
			--j;
			++k;
		}
		std::string diag_ne = diag_sw;
		std::reverse(diag_ne.begin(), diag_ne.end());

		all_lines.push_back(diag_sw);
		all_lines.push_back(diag_ne);
		--i;
	}

	i = 1;
	while (i < lines.size())
	{
		size_t j = i;
		size_t k = lines[0].size() - 1;
		std::string diag_se;
		while (j < lines.size() && k >= 0 && k < lines[0].size())
		{
			diag_se.push_back(lines[j][k]);
			++j;
			--k;
		}
		std::string diag_nw = diag_se;
		std::reverse(diag_nw.begin(), diag_nw.end());

		all_lines.push_back(diag_se);
		all_lines.push_back(diag_nw);
		++i;
	}
}

long long part_one(std::vector<std::string> lines)
{
	std::vector<std::string> all_lines;
	
	add_hor_lines(lines, all_lines);
	add_vert_lines(lines, all_lines);
	add_diag_lines(lines, all_lines);

	return (count_xmas(all_lines));
}

long long part_two(std::vector<std::string> lines)
{
	long long x_mas = 0;
	size_t y = 1;
	while (y < lines.size() - 1)
	{
		size_t x = 1;
		while (x < lines[y].size() - 1)
		{
			if (lines[y][x] == 'A')
			{
				if (((lines[y - 1][x - 1] == 'M' && lines[y + 1][x + 1] == 'S') ||
					(lines[y - 1][x - 1] == 'S' && lines[y + 1][x + 1] == 'M')) &&
					((lines[y + 1][x - 1] == 'M' && lines[y - 1][x + 1] == 'S') ||
					(lines[y + 1][x - 1] == 'S' && lines[y - 1][x + 1] == 'M')))
					++x_mas;
			}
			++x;
		}
		++y;
	}
	return (x_mas);
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
