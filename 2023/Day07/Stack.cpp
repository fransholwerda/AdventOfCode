#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Stack.hpp"
#include "Hand.hpp"

Stack::Stack(std::vector<Hand> unsortedHands)
{
	this->_unsortedHands = unsortedHands;
}

Stack::~Stack()
{
}

std::vector<Hand>	Stack::get_unsortedHands()
{
	return (this->_unsortedHands);
}

std::vector<Hand>	Stack::get_fiveOfAKind()
{
	return (this->_fiveOfAKind);
}

std::vector<Hand>	Stack::get_fourOfAKind()
{
	return (this->_fourOfAKind);
}

std::vector<Hand>	Stack::get_fullHouse()
{
	return (this->_fullHouse);
}

std::vector<Hand>	Stack::get_threeOfAKind()
{
	return (this->_threeOfAKind);
}

std::vector<Hand>	Stack::get_twoPairs()
{
	return (this->_twoPairs);
}

std::vector<Hand>	Stack::get_pair()
{
	return (this->_pair);
}

std::vector<Hand>	Stack::get_highCard()
{
	return (this->_highCard);
}

void				Stack::set_unsortedHands(std::vector<Hand> unsortedHands)
{
	this->_unsortedHands = unsortedHands;
}

void				Stack::set_fiveOfAKind(std::vector<Hand> fiveOfAKind)
{
	this->_fiveOfAKind = fiveOfAKind;
}

void				Stack::set_fourOfAKind(std::vector<Hand> fourOfAKind)
{
	this->_fourOfAKind = fourOfAKind;
}

void				Stack::set_fullHouse(std::vector<Hand> fullHouse)
{
	this->_fullHouse = fullHouse;
}

void				Stack::set_threeOfAKind(std::vector<Hand> threeOfAKind)
{
	this->_threeOfAKind = threeOfAKind;
}

void				Stack::set_twoPairs(std::vector<Hand> twoPairs)
{
	this->_twoPairs = twoPairs;
}

void				Stack::set_pair(std::vector<Hand> pair)
{
	this->_pair = pair;
}

bool detect_five_of_a_kind(std::string cards, bool joker = false)
{
	for (int i = 0; i < 5; i++)
	{
		char c = cards[i];
		if (c == 'J' && std::count(cards.begin(), cards.end(), 'J') == 5)
			return (true);
		if (c == 'J' && joker)
			continue;
		std::string::difference_type count = std::count(cards.begin(), cards.end(), c);
		if (joker)
			count += std::count(cards.begin(), cards.end(), 'J');
		if (count == 5)
			return (true);
	}
	return (false);
}

bool detect_four_of_a_kind(std::string cards, bool joker = false)
{
	for (int i = 0; i < 5; i++)
	{
		char c = cards[i];
		if (c == 'J' && joker)
			continue;
		std::string::difference_type count = std::count(cards.begin(), cards.end(), c);
		if (joker)
			count += std::count(cards.begin(), cards.end(), 'J');
		if (count == 4)
			return (true);
	}
	return (false);
}

bool detect_full_house(std::string cards, bool joker = false)
{
	if (joker && std::count(cards.begin(), cards.end(), 'J') >= 1)
	{
		std::string::difference_type count_joker = std::count(cards.begin(), cards.end(), 'J');
		if (count_joker == 1)
		{
			char c_first = cards[0];
			if (c_first == 'J')
				c_first = cards[1];
			std::string::difference_type count_first = std::count(cards.begin(), cards.end(), c_first);
			if (count_first == 2)
			{
				char c_second;
				int i = cards.find_first_of(c_first) + 1;
				while (cards[i] == c_first || cards[i] == 'J')
					i++;
				while (i < 5)
				{
					if (cards[i] != c_first)
					{
						c_second = cards[i];
						break;
					}
					i++;
				}
				std::string::difference_type count_second = std::count(cards.begin(), cards.end(), c_second);
				if (count_second == 2)
					return (true);
			}
		}
	}
	else
	{
		char c_first = cards[0];
		std::string::difference_type count_first = std::count(cards.begin(), cards.end(), c_first);
		if (count_first == 2 || count_first == 3)
		{
			char c_second;
			for (int i = 0; i < 5; i++)
			{
				if (cards[i] != c_first)
				{
					c_second = cards[i];
					break;
				}
			}
			std::string::difference_type count_second = std::count(cards.begin(), cards.end(), c_second);
			if ((count_first == 2 && count_second == 3) || (count_first == 3 && count_second == 2))
				return (true);
		}
	}
	return (false);
}

bool detect_three_of_a_kind(std::string cards, bool joker = false)
{
	for (int i = 0; i < 5; i++)
	{
		if (joker && cards[i] == 'J')
			continue;
		char c = cards[i];
		std::string::difference_type count = std::count(cards.begin(), cards.end(), c);
		if (joker)
			count += std::count(cards.begin(), cards.end(), 'J');
		if (count == 3)
			return (true);
	}
	return (false);
}

bool detect_two_pair(std::string cards)
{
	for (int i = 0; i < 2; i++)
	{
		char c = cards[i];
		std::string::difference_type count = std::count(cards.begin(), cards.end(), c);
		if (count == 2)
		{
			for (int j = i + 1; j < 4; j++)
			{
				if (cards[j] != c)
				{
					char c_second = cards[j];
					std::string::difference_type count_second = std::count(cards.begin(), cards.end(), c_second);
					if (count_second == 2)
						return (true);
				}
			}
		}
	}
	return (false);
}

bool detect_one_pair(std::string cards, bool joker = false)
{
	for (int i = 0; i < 5; i++)
	{
		if (cards[i] == 'J' && joker)
			continue;
		char c = cards[i];
		std::string::difference_type count = std::count(cards.begin(), cards.end(), c);
		if (joker)
			count += std::count(cards.begin(), cards.end(), 'J');
		if (count == 2)
			return (true);
	}
	return (false);
}

void Stack::divide_hands(bool joker)
{
	for (size_t i = 0; i < this->_unsortedHands.size(); i++)
	{
		std::string cards = this->_unsortedHands[i].get_cards();
		if (detect_five_of_a_kind(cards, joker))
			this->_fiveOfAKind.push_back(this->_unsortedHands[i]);
		else if (detect_four_of_a_kind(cards, joker))
			this->_fourOfAKind.push_back(this->_unsortedHands[i]);
		else if (detect_full_house(cards, joker))
			this->_fullHouse.push_back(this->_unsortedHands[i]);
		else if (detect_three_of_a_kind(cards, joker))
			this->_threeOfAKind.push_back(this->_unsortedHands[i]);
		else if (detect_two_pair(cards))
			this->_twoPairs.push_back(this->_unsortedHands[i]);
		else if (detect_one_pair(cards, joker))
			this->_pair.push_back(this->_unsortedHands[i]);
		else
			this->_highCard.push_back(this->_unsortedHands[i]);
	}
}

struct less_than_key
{
	inline bool operator() (Hand hand1, Hand hand2)
	{
		std::string value_order = "23456789TJQKA";
		size_t i = 0;
		while (i < hand1.get_cards().length())
		{
			if (value_order.find(hand1.get_cards()[i]) < value_order.find(hand2.get_cards()[i]))
				return (true);
			else if (value_order.find(hand1.get_cards()[i]) > value_order.find(hand2.get_cards()[i]))
				return (false);
			i++;
		}
		return (false);
	}
};

struct less_than_key_joker
{
	inline bool operator() (Hand hand1, Hand hand2)
	{
		std::string value_order = "J23456789TQKA";
		size_t i = 0;
		while (i < hand1.get_cards().length())
		{
			if (value_order.find(hand1.get_cards()[i]) < value_order.find(hand2.get_cards()[i]))
				return (true);
			else if (value_order.find(hand1.get_cards()[i]) > value_order.find(hand2.get_cards()[i]))
				return (false);
			i++;
		}
		return (false);
	}
};

std::vector<Hand> Stack::sort_hands(std::vector<Hand> hands, bool joker)
{
	if (joker)
		std::sort(hands.begin(), hands.end(), less_than_key_joker());
	else
		std::sort(hands.begin(), hands.end(), less_than_key());
	return (hands);
}

void Stack::sort_stack(bool joker)
{
	this->_fiveOfAKind = sort_hands(this->_fiveOfAKind, joker);
	this->_fourOfAKind = sort_hands(this->_fourOfAKind, joker);
	this->_fullHouse = sort_hands(this->_fullHouse, joker);
	this->_threeOfAKind = sort_hands(this->_threeOfAKind, joker);
	this->_twoPairs = sort_hands(this->_twoPairs, joker);
	this->_pair = sort_hands(this->_pair, joker);
	this->_highCard = sort_hands(this->_highCard, joker);
}

long long Stack::get_stack_score(void)
{
	long long rank = 1;
	long long score = 0;
	size_t i = 0;
	while (i < this->_highCard.size())
	{
		score += rank * this->_highCard[i].get_value();
		rank++;
		i++;
	}
	i = 0;
	while (i < this->_pair.size())
	{
		score += rank * this->_pair[i].get_value();
		rank++;
		i++;
	}
	i = 0;
	while (i < this->_twoPairs.size())
	{
		score += rank * this->_twoPairs[i].get_value();
		rank++;
		i++;
	}
	i = 0;
	while (i < this->_threeOfAKind.size())
	{
		score += rank * this->_threeOfAKind[i].get_value();
		rank++;
		i++;
	}
	i = 0;
	while (i < this->_fullHouse.size())
	{
		score += rank * this->_fullHouse[i].get_value();
		rank++;
		i++;
	}
	i = 0;
	while (i < this->_fourOfAKind.size())
	{
		score += rank * this->_fourOfAKind[i].get_value();
		rank++;
		i++;
	}
	i = 0;
	while (i < this->_fiveOfAKind.size())
	{
		score += rank * this->_fiveOfAKind[i].get_value();
		rank++;
		i++;
	}
	return (score);
}

void Stack::print_hands(void)
{
	std::cout << "Five of a kind:" << std::endl;
	for (size_t i = 0; i < this->_fiveOfAKind.size(); i++)
		std::cout << this->_fiveOfAKind[i].get_cards() << " -> " << this->_fiveOfAKind[i].get_value() << std::endl;
	std::cout << "Four of a kind:" << std::endl;
	for (size_t i = 0; i < this->_fourOfAKind.size(); i++)
		std::cout << this->_fourOfAKind[i].get_cards() << " -> " << this->_fourOfAKind[i].get_value() << std::endl;
	std::cout << "Full house:" << std::endl;
	for (size_t i = 0; i < this->_fullHouse.size(); i++)
		std::cout << this->_fullHouse[i].get_cards() << " -> " << this->_fullHouse[i].get_value() << std::endl;
	std::cout << "Three of a kind:" << std::endl;
	for (size_t i = 0; i < this->_threeOfAKind.size(); i++)
		std::cout << this->_threeOfAKind[i].get_cards() << " -> " << this->_threeOfAKind[i].get_value() << std::endl;
	std::cout << "Two pairs:" << std::endl;
	for (size_t i = 0; i < this->_twoPairs.size(); i++)
		std::cout << this->_twoPairs[i].get_cards() << " -> " << this->_twoPairs[i].get_value() << std::endl;
	std::cout << "Pair:" << std::endl;
	for (size_t i = 0; i < this->_pair.size(); i++)
		std::cout << this->_pair[i].get_cards() << " -> " << this->_pair[i].get_value() << std::endl;
	std::cout << "High card:" << std::endl;
	for (size_t i = 0; i < this->_highCard.size(); i++)
		std::cout << this->_highCard[i].get_cards() << " -> " << this->_highCard[i].get_value() << std::endl;
}
