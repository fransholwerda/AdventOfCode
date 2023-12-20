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

long long gcd(long long a, long long b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

long long lcm(std::vector<long long> v, size_t n)
{
	long long ans = v[0];
	for (size_t i = 1; i < n; i++)
		ans = (((v[i] * ans)) / (gcd(v[i], ans)));
	return (ans);
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

	std::string instructions = lines[0];
	std::map<std::string, std::vector<std::string>> network;
	std::vector<std::string> starts;

	size_t i = 2;
	while (i < lines.size())
	{
		std::vector<std::string> node = split(lines[i], " = ");
		network[node[0]] = split(node[1].substr(1, node[1].length() - 2), ", ");
		if (node[0][2] == 'A')
			starts.push_back(node[0]);
		i++;
	}

	std::string current_node = "AAA";
	int answer_part_one = 0;
	i = 0;
	while (current_node != "ZZZ")
	{
		if (instructions[i] == 'L')
			current_node = network[current_node][0];
		else
			current_node = network[current_node][1];
		answer_part_one++;
		if (i == instructions.length() - 1)
			i = 0;
		else
			i++;
	}
	std::cout << "Part one: " << answer_part_one << std::endl;

	std::vector<long long> visited;
	i = 0;
	for (size_t j = 0; j < starts.size(); j++)
	{
		long long it = 0;
		i = 0;
		while (true)
		{
			if (starts[j][2] == 'Z')
			{
				visited.push_back(it);
				break ;
			}
			if (instructions[i] == 'L')
				starts[j] = network[starts[j]][0];
			else
				starts[j] = network[starts[j]][1];
			if (i == instructions.length() - 1)
				i = 0;
			else
				i++;
			it++;
		}
	}
	long long answer_part_two = lcm(visited, visited.size());
	std::cout << "Part two: " << answer_part_two << std::endl;

	return (EXIT_SUCCESS);
}
