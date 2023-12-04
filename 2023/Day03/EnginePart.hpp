#ifndef ENGINE_PART_HPP
# define ENGINE_PART_HPP

class EnginePart
{
	private:
		int		_value;
		int		_x;
		int		_y;
		int		_length;
		bool	_adjacent;

	public:
		EnginePart(int value, int x, int y, int length, bool adjacent);
		~EnginePart(void);

		int		getValue(void) const;
		int		getX(void) const;
		int		getY(void) const;
		int		getLength(void) const;
		bool	isAdjacent(void) const;

		void	setAdjacent(bool adjacent);
};

#endif
