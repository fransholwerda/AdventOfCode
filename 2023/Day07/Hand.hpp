#ifndef HAND_HPP
# define HAND_HPP

# include <iostream>

enum class HandType
{
	None,
	HighCard,
	Pair,
	TwoPairs,
	ThreeOfAKind,
	FullHouse,
	FourOfAKind,
	FiveOfAKind
};

class Hand
{
	private:
		std::string	_cards;
		HandType	_type;
		long long	_value;
	public:
		Hand(std::string cards, long long value);
		~Hand();

		HandType	get_type();
		std::string	get_cards();
		long long	get_value();
		
		void		set_type(HandType type);
};

#endif
