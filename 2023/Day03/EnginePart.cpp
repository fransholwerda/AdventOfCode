#include "EnginePart.hpp"

EnginePart::EnginePart(int value, int x, int y, int length, bool adjacent) : _value(value), _x(x), _y(y), _length(length), _adjacent(adjacent)
{
}

EnginePart::~EnginePart(void)
{
}

int	EnginePart::getValue(void) const
{
	return (this->_value);
}

int	EnginePart::getX(void) const
{
	return (this->_x);
}

int	EnginePart::getY(void) const
{
	return (this->_y);
}

int	EnginePart::getLength(void) const
{
	return (this->_length);
}

bool	EnginePart::isAdjacent(void) const
{
	return (this->_adjacent);
}

void	EnginePart::setAdjacent(bool adjacent)
{
	this->_adjacent = adjacent;
}
