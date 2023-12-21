#include <iostream>
#include "Hand.hpp"

Hand::Hand(std::string cards, long long value)
{
	this->_cards = cards;
	this->_type = HandType::None;
	this->_value = value;
}

Hand::~Hand()
{
}

HandType	Hand::get_type()
{
	return (this->_type);
}

std::string	Hand::get_cards()
{
	return (this->_cards);
}

void	Hand::set_type(HandType type)
{
	this->_type = type;
}

long long Hand::get_value()
{
	return (this->_value);
}
