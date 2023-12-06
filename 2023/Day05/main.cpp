#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <limits.h>

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

long long convert_unit(long long unit, std::vector<std::vector<long long>> table)
{
	for (std::vector<long long> i : table)
	{
		if (unit >= i[1] && unit < i[1] + i[2])
			return (i[0] - i[1] + unit);
	}
	return (unit);
}

std::vector<long long> convert_seeds_to_locations(
	std::vector<long long> seeds,
	std::vector<std::vector<long long>> seed_to_soil,
	std::vector<std::vector<long long>> soil_to_fertilizer,
	std::vector<std::vector<long long>> fertilizer_to_water,
	std::vector<std::vector<long long>> water_to_light,
	std::vector<std::vector<long long>> light_to_temperature,
	std::vector<std::vector<long long>> temperature_to_humidity,
	std::vector<std::vector<long long>> humidity_to_location)
{
	std::vector<long long> result;
	for (long long seed : seeds)
	{
		long long soil = convert_unit(seed, seed_to_soil);
		long long fertilizer = convert_unit(soil, soil_to_fertilizer);
		long long water = convert_unit(fertilizer, fertilizer_to_water);
		long long light = convert_unit(water, water_to_light);
		long long temperature = convert_unit(light, light_to_temperature);
		long long humidity = convert_unit(temperature, temperature_to_humidity);
		long long location = convert_unit(humidity, humidity_to_location);
		result.push_back(location);
	}
	return (result);
}

std::vector<long long> convert_ranges(std::vector<long long> ranges, std::vector<std::vector<long long>> table)
{
	std::vector<long long> new_ranges;

	size_t i = 0;
	while (i < ranges.size())
	{
		std::vector<long long> temp_ranges;
		temp_ranges.push_back(ranges[i]);
		temp_ranges.push_back(ranges[i] + ranges[i + 1] - 1);
		while (!temp_ranges.empty())
		{
			bool found = false;
			for (std::vector<long long> j : table)
			{
				if ((temp_ranges[0] >= j[1] && temp_ranges[0] < j[1] + j[2]) &&
					(temp_ranges[1] < j[1] + j[2])) // If range is fully within the table range
				{
					long long start = temp_ranges[0] + j[0] - j[1];
					long long length = temp_ranges[1] - temp_ranges[0] + 1;
					new_ranges.push_back(start);
					new_ranges.push_back(length);
					temp_ranges.erase(temp_ranges.begin());
					temp_ranges.erase(temp_ranges.begin());
					found = true;
				}
				else if ((temp_ranges[0] < j[1]) &&
					(temp_ranges[1] >= j[1] && temp_ranges[1] < j[1] + j[2])) // If start of range is before table range and end of range is within table range
				{
					long long start = j[0];
					long long length = j[0] - j[1] + temp_ranges[1] - start + 1;
					new_ranges.push_back(start);
					new_ranges.push_back(length);
					temp_ranges[1] = j[1] - 1;
					found = true;
				}
				else if ((temp_ranges[0] >= j[1] && temp_ranges[0] < j[1] + j[2]) &&
					(temp_ranges[1] >= j[1] + j[2])) // If start of range is within table range and end of range is after table range
				{
					long long start = temp_ranges[0] + j[0] - j[1];
					long long length = j[1] + j[2] - temp_ranges[0];
					new_ranges.push_back(start);
					new_ranges.push_back(length);
					temp_ranges[0] = j[1] + j[2];
					found = true;
				}
				else if ((temp_ranges[0] < j[1]) &&
					(temp_ranges[1] > j[1] + j[2])) // If start of range is before table range and end of range is after table range
				{
					long long start = j[0];
					long long length = j[2];
					new_ranges.push_back(start);
					new_ranges.push_back(length);
					long long temp = temp_ranges[1];
					temp_ranges[1] = j[1] - 1;
					temp_ranges.push_back(j[1] + j[2]);
					temp_ranges.push_back(temp);
					found = true;
				}
				if (temp_ranges.empty())
					break;
			}
			if (!found)
			{
				new_ranges.push_back(temp_ranges[0]);
				new_ranges.push_back(temp_ranges[1] - temp_ranges[0] + 1);
				temp_ranges.erase(temp_ranges.begin());
				temp_ranges.erase(temp_ranges.begin());
			}
		}
		i += 2;
	}
	return (new_ranges);
}

std::vector<long long> convert_seedranges_to_locationranges(
	std::vector<long long> seed_ranges,
	std::vector<std::vector<long long>> seed_to_soil,
	std::vector<std::vector<long long>> soil_to_fertilizer,
	std::vector<std::vector<long long>> fertilizer_to_water,
	std::vector<std::vector<long long>> water_to_light,
	std::vector<std::vector<long long>> light_to_temperature,
	std::vector<std::vector<long long>> temperature_to_humidity,
	std::vector<std::vector<long long>> humidity_to_location)
{
	std::vector<long long> soil_ranges = convert_ranges(seed_ranges, seed_to_soil);
	std::vector<long long> fertilizer_ranges = convert_ranges(soil_ranges, soil_to_fertilizer);
	std::vector<long long> water_ranges = convert_ranges(fertilizer_ranges, fertilizer_to_water);
	std::vector<long long> light_ranges = convert_ranges(water_ranges, water_to_light);
	std::vector<long long> temperature_ranges = convert_ranges(light_ranges, light_to_temperature);
	std::vector<long long> humidity_ranges = convert_ranges(temperature_ranges, temperature_to_humidity);
	std::vector<long long> location_ranges = convert_ranges(humidity_ranges, humidity_to_location);
	return (location_ranges);
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

	std::vector<long long> seeds = split_longlong(&lines[0][7], " ");
	size_t cursor = 3;
	std::vector<std::vector<long long>> seed_to_soil;
	while (!lines[cursor].empty())
		seed_to_soil.push_back(split_longlong(lines[cursor++], " "));
	cursor += 2;

	std::vector<std::vector<long long>> soil_to_fertilizer;
	while (!lines[cursor].empty())
		soil_to_fertilizer.push_back(split_longlong(lines[cursor++], " "));
	cursor += 2;

	std::vector<std::vector<long long>> fertilizer_to_water;
	while (!lines[cursor].empty())
		fertilizer_to_water.push_back(split_longlong(lines[cursor++], " "));
	cursor += 2;

	std::vector<std::vector<long long>> water_to_light;
	while (!lines[cursor].empty())
		water_to_light.push_back(split_longlong(lines[cursor++], " "));
	cursor += 2;

	std::vector<std::vector<long long>> light_to_temperature;
	while (!lines[cursor].empty())
		light_to_temperature.push_back(split_longlong(lines[cursor++], " "));
	cursor += 2;

	std::vector<std::vector<long long>> temperature_to_humidity;
	while (!lines[cursor].empty())
		temperature_to_humidity.push_back(split_longlong(lines[cursor++], " "));
	cursor += 2;

	std::vector<std::vector<long long>> humidity_to_location;
	while (!lines[cursor].empty())
		humidity_to_location.push_back(split_longlong(lines[cursor++], " "));

	std::vector<long long> locations = convert_seeds_to_locations(
		seeds,
		seed_to_soil,
		soil_to_fertilizer,
		fertilizer_to_water,
		water_to_light,
		light_to_temperature,
		temperature_to_humidity,
		humidity_to_location);

	long long answer_part_one = LONG_LONG_MAX;
	for (long long i : locations)
	{
		if (i < answer_part_one)
			answer_part_one = i;
	}
	std::cout << "Part one: " << answer_part_one << std::endl;

	std::vector<long long> location_ranges = convert_seedranges_to_locationranges(
		seeds,
		seed_to_soil,
		soil_to_fertilizer,
		fertilizer_to_water,
		water_to_light,
		light_to_temperature,
		temperature_to_humidity,
		humidity_to_location);

	long long answer_part_two = LONG_LONG_MAX;
	size_t i = 0;
	while (i < location_ranges.size())
	{
		if (location_ranges[i] < answer_part_two)
			answer_part_two = location_ranges[i];
		i += 2;
	}
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
