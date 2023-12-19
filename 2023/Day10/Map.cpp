#include <iostream>
#include <vector>
#include "Map.hpp"

Map::Map(void)
{
}

Map::~Map(void)
{
}

long long Map::get_startX(void) const
{
	return (_startX);
}

long long Map::get_startY(void) const
{
	return (_startY);
}

long long Map::get_x(void) const
{
	return (_x);
}

long long Map::get_y(void) const
{
	return (_y);
}

std::vector<std::vector<long long>> Map::get_map(void) const
{
	return (_map);
}

void Map::set_startX(long long startX)
{
	_startX = startX;
}

void Map::set_startY(long long startY)
{
	_startY = startY;
}

void Map::set_x(long long x)
{
	_x = x;
}

void Map::set_y(long long y)
{
	_y = y;
}

void Map::fill_map(std::vector<std::string> data)
{
	long long y = 0;
	while (y < static_cast<long long>(data.size()))
	{
		std::vector<long long> row;
		long long x = 0;
		while (x < static_cast<long long>(data[y].length()))
		{
			if (data[y][x] == 'S')
			{
				_startX = x;
				_startY = y;
				row.push_back(0);
			}
			else
				row.push_back(-1);
			x++;
		}
		y++;
		_map.push_back(row);
	}
}

bool is_in(char c, std::string str)
{
	if (str.find(c) != std::string::npos)
		return (true);
	return (false);
}

std::vector<long long> find_connected_pipes(std::vector<std::string> data, long long x, long long y)
{
	std::vector<long long> pipe_pos;
	if (data[y][x] == 'S')
	{
		if (x - 1 >= 0 && is_in(data[y][x-1], "-LF"))
		{
			pipe_pos.push_back(x-1);
			pipe_pos.push_back(y);
		}
		if (x + 1 < static_cast<long long>(data[y].length()) && is_in(data[y][x+1], "-J7"))
		{
			pipe_pos.push_back(x+1);
			pipe_pos.push_back(y);
		}
		if (y - 1 >= 0 && is_in(data[y-1][x], "|F7"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y-1);
		}
		if (y + 1 < static_cast<long long>(data.size()) && is_in(data[y+1][x], "|LJ"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y+1);
		}
	}
	else if (data[y][x] == '|')
	{
		if (y - 1 >= 0 && is_in(data[y-1][x], "|F7"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y-1);
		}
		if (y + 1 < static_cast<long long>(data.size()) && is_in(data[y+1][x], "|LJ"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y+1);
		}
	}
	else if (data[y][x] == '-')
	{
		if (x - 1 >= 0 && is_in(data[y][x-1], "-LF"))
		{
			pipe_pos.push_back(x-1);
			pipe_pos.push_back(y);
		}
		if (x + 1 < static_cast<long long>(data[y].length()) && is_in(data[y][x+1], "-J7"))
		{
			pipe_pos.push_back(x+1);
			pipe_pos.push_back(y);
		}
	}
	else if (data[y][x] == 'L')
	{
		if (y - 1 >= 0 && is_in(data[y-1][x], "|F7"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y-1);
		}
		if (x + 1 < static_cast<long long>(data[y].length()) && is_in(data[y][x+1], "-J7"))
		{
			pipe_pos.push_back(x+1);
			pipe_pos.push_back(y);
		}
	}
	else if (data[y][x] == 'J')
	{
		if (x - 1 >= 0 && is_in(data[y][x-1], "-LF"))
		{
			pipe_pos.push_back(x-1);
			pipe_pos.push_back(y);
		}
		if (y - 1 >= 0 && is_in(data[y-1][x], "|F7"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y-1);
		}
	}
	else if (data[y][x] == '7')
	{
		if (x - 1 >= 0 && is_in(data[y][x-1], "-LF"))
		{
			pipe_pos.push_back(x-1);
			pipe_pos.push_back(y);
		}
		if (y + 1 < static_cast<long long>(data.size()) && is_in(data[y+1][x], "|LJ"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y+1);
		}
	}
	else if (data[y][x] == 'F')
	{
		if (x + 1 < static_cast<long long>(data[y].length()) && is_in(data[y][x+1], "-J7"))
		{
			pipe_pos.push_back(x+1);
			pipe_pos.push_back(y);
		}
		if (y + 1 < static_cast<long long>(data.size()) && is_in(data[y+1][x], "|LJ"))
		{
			pipe_pos.push_back(x);
			pipe_pos.push_back(y+1);
		}
	}
	return (pipe_pos);
}

long long Map::make_main_pipe(std::vector<std::string> data)
{
	std::vector<long long> pipe_pos = find_connected_pipes(data, _startX, _startY);
	long long incr = 2;
	long long side = -1;
	long long furthest = 0;
	std::vector<long long> prev_pos;
	prev_pos.push_back(_startX);
	prev_pos.push_back(_startY);
	prev_pos.push_back(_startX);
	prev_pos.push_back(_startY);

	while (!(pipe_pos[0] == pipe_pos[2] && pipe_pos[1] == pipe_pos[3]))
	{
		_map[pipe_pos[2+side]][pipe_pos[1+side]] += incr;
		std::vector<long long> temp = find_connected_pipes(data, pipe_pos[1+side], pipe_pos[2+side]);
		if (!(temp[0] == prev_pos[1+side] && temp[1] == prev_pos[2+side]))
		{
			prev_pos[1+side] = pipe_pos[1+side];
			prev_pos[2+side] = pipe_pos[2+side];
			pipe_pos[1+side] = temp[0];
			pipe_pos[2+side] = temp[1];
		}
		else
		{
			prev_pos[1+side] = pipe_pos[1+side];
			prev_pos[2+side] = pipe_pos[2+side];
			pipe_pos[1+side] = temp[2];
			pipe_pos[2+side] = temp[3];
		}
		if (side == -1)
			side = 1;
		else
		{
			incr++;
			side = -1;
		}
		if (pipe_pos[0] == pipe_pos[2] && pipe_pos[1] == pipe_pos[3])
			_map[pipe_pos[1]][pipe_pos[0]] += incr;
		if (_map[pipe_pos[2+side]][pipe_pos[1+side]] > furthest)
			furthest = _map[pipe_pos[2+side]][pipe_pos[1+side]];
	}
	return (furthest);
}

bool Map::connected_to_edge(long long x, long long y, long long x_size, long long y_size)
{
	for (std::vector<long long> visit : _visited)
	{
		if (x == visit[0] && y == visit[1])
			return (false);
	}
	_visited.push_back({x, y});
	if (x <= 0 || x >= x_size - 1 ||
		y <= 0 || y >= y_size - 1)
		return (true);
	if (_map[y][x] >= 0)
		return (false);
	if (connected_to_edge(x-1, y, x_size, y_size))
		return (true);
	if (connected_to_edge(x+1, y, x_size, y_size))
		return (true);
	if (connected_to_edge(x, y-1, x_size, y_size))
		return (true);
	if (connected_to_edge(x, y+1, x_size, y_size))
		return (true);
	return (false);
}

void Map::flood_fill(long long x, long long y, bool edge)
{
	if (x >= 0 && x <= static_cast<long long>(_map[0].size() -1) &&
		y >= 0 && y <= static_cast<long long>(_map.size() - 1))
	{
		if (_map[y][x] != -1)
			return;
		if (edge)
			_map[y][x] = -2;
		else
			_map[y][x] = -3;
	}
	else
		return;
	flood_fill(x-1, y, edge);
	flood_fill(x+1, y, edge);
	flood_fill(x, y-1, edge);
	flood_fill(x, y+1, edge);
}

void Map::clear_visited(void)
{
	_visited.clear();
}
