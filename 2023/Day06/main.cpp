#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
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

std::vector<long long> get_race_results(long long time, long long distance)
{
	std::vector<long long> race;
	long long ms = 0, speed = 0;
	while (ms <= time)
	{
		long long distance_travelled = (time - ms) * speed;
		if (distance_travelled > distance)
		{
			long long time_to_dest = ms + static_cast<long long>(static_cast<float>(distance) / static_cast<float>(speed));
			race.push_back(time_to_dest);
		}
		ms++, speed++;
	}
	return (race);
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

	std::vector<long long> times = split_longlong(lines[0], " ");
	std::vector<long long> distances = split_longlong(lines[1], " ");
	std::vector<std::vector<long long>> races;

	size_t i = 0;
	while (i < times.size())
	{
		races.push_back(get_race_results(times[i], distances[i]));
		i++;
	}
	int answer_part_one = 1;
	for (std::vector<long long> race : races)
		answer_part_one *= race.size();
	std::cout << "Part one: " << answer_part_one << std::endl;

	// UGLY BRUTEFORCE BECAUSE WHY NOT
	std::string combine_number = &lines[0][5];
	combine_number.erase(std::remove_if(combine_number.begin(), combine_number.end(), ::isspace), combine_number.end());
	long long time = stoll(combine_number);
	combine_number = &lines[1][9];
	combine_number.erase(std::remove_if(combine_number.begin(), combine_number.end(), ::isspace), combine_number.end());
	long long distance = stoll(combine_number);

	std::vector<long long> race_result = get_race_results(time, distance);
	long long answer_part_two = race_result.size();
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
