#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <vector>
# include "Hand.hpp"

class Stack
{
	private:
		std::vector<Hand>	_unsortedHands;
		std::vector<Hand>	_fiveOfAKind;
		std::vector<Hand>	_fourOfAKind;
		std::vector<Hand>	_fullHouse;
		std::vector<Hand>	_threeOfAKind;
		std::vector<Hand>	_twoPairs;
		std::vector<Hand>	_pair;
		std::vector<Hand>	_highCard;
	public:
		Stack(std::vector<Hand> unsortedHands);
		~Stack();

		std::vector<Hand>			get_unsortedHands();
		std::vector<Hand>			get_fiveOfAKind();
		std::vector<Hand>			get_fourOfAKind();
		std::vector<Hand>			get_fullHouse();
		std::vector<Hand>			get_threeOfAKind();
		std::vector<Hand>			get_twoPairs();
		std::vector<Hand>			get_pair();
		std::vector<Hand>			get_highCard();

		void	set_unsortedHands(std::vector<Hand> unsortedHands);
		void	set_fiveOfAKind(std::vector<Hand> fiveOfAKind);
		void	set_fourOfAKind(std::vector<Hand> fourOfAKind);
		void	set_fullHouse(std::vector<Hand> fullHouse);
		void	set_threeOfAKind(std::vector<Hand> threeOfAKind);
		void	set_twoPairs(std::vector<Hand> twoPairs);
		void	set_pair(std::vector<Hand> pair);
		void	set_highCard(std::vector<Hand> highCard);

		void	divide_hands(bool joker);
		std::vector<Hand>	sort_hands(std::vector<Hand> hands, bool joker);
		void	sort_stack(bool joker);
		long long	get_stack_score(void);
		void	print_hands(void);
};

#endif
