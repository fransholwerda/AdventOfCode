#include <iostream>
#include <fstream>
#include <map>
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

std::vector<int> split_int(std::string str, std::string delim)
{
	std::vector<int> result;
	size_t pos = 0;
	while ((pos = str.find(delim)) != std::string::npos)
	{
		try
		{
			result.push_back(std::stoi(str.substr(0, pos)));
		}
		catch(const std::exception& e)
		{
		}
		str.erase(0, pos + delim.length());
	}
	result.push_back(std::stoi(str));
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

	std::map<int, int> card_copies;
	size_t i = 0;
	while (i < lines.size())
	{
		card_copies[i + 1] = 1;
		i++;
	}

	int answer_part_one = 0;
	i = 1;
	for (auto line : lines)
	{
		size_t j = i + 1;
		int points = 0;
		std::vector<std::string> data = split(line, " | ");
		data[0] = data[0].substr(data[0].find(": ") + 2, data[0].length());
		std::vector<int> card_numbers = split_int(data[0], " ");
		std::vector<int> own_numbers = split_int(data[1], " ");
		for (auto card_number : card_numbers)
		{
			for (auto own_number : own_numbers)
			{
				if (card_number == own_number)
				{
					if (points == 0)
						points++;
					else
						points *= 2;
					if (card_copies.find(j) != card_copies.end())
					{
						card_copies[j] += card_copies[i];
						j++;
					}
				}
			}
		}
		answer_part_one += points;
		i++;
	}

	std::cout << "Part one: " << answer_part_one << std::endl;

	int answer_part_two = 0;
	for (auto const &card : card_copies)
	{
		answer_part_two += card.second;
	}

	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
