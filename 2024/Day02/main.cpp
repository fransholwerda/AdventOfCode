#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

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

bool is_safe(std::vector<long long> report)
{
	bool safe = true;
	bool increasing = true;
	if (report[1] < report[0])
		increasing = false;
	size_t i = 1;
	while (i < report.size())
	{
		if ((report[i] > report[i - 1] && !increasing) ||
			(report[i] < report[i - 1] && increasing))
		{
			safe = false;
			break;
		}
		long long diff = abs(report[i] - report[i - 1]);
		if (diff < 1 || diff > 3)
		{
			safe = false;
			break;
		}
		++i;
	}
	return (safe);
}

bool dampener_safe(std::vector<long long> report)
{
	size_t i = 0;
	while(i < report.size())
	{
		std::vector<long long> dup_report;
		dup_report.assign(report.begin(), report.end());
		dup_report.erase(dup_report.begin() + i);
		if (is_safe(dup_report))
			return (true);
		i++;
	}
	return (false);
}

long long part_one(std::vector<std::string> lines)
{
	long long safe_reports = 0;
	for (std::string line : lines)
	{
		std::vector<long long> report = split_longlong(line, " ");
		if (is_safe(report))
			++safe_reports;
	}
	return (safe_reports);
}

long long part_two(std::vector<std::string> lines)
{
	long long safe_reports = 0;
	for (std::string line : lines)
	{
		std::vector<long long> report = split_longlong(line, " ");
		if (dampener_safe(report))
			++safe_reports;
	}
	return (safe_reports);
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
