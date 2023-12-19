#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <vector>

class Map
{
	private:
		long long	_startX;
		long long	_startY;
		long long	_x;
		long long	_y;
		std::vector<std::vector<long long>>	_visited;
		std::vector<std::vector<long long>>	_map;

	public:
		Map(void);
		~Map(void);

		long long	get_startX(void) const;
		long long	get_startY(void) const;
		long long	get_x() const;
		long long	get_y() const;
		std::vector<std::vector<long long>>	get_map() const;

		void		set_startX(long long startX);
		void		set_startY(long long startY);
		void		set_x(long long x);
		void		set_y(long long y);
		void		fill_map(std::vector<std::string> data);

		long long	make_main_pipe(std::vector<std::string> data);

		bool		connected_to_edge(long long x, long long y, long long x_size, long long y_size);
		void		flood_fill(long long x, long long y, bool edge);
		void		clear_visited(void);
};

#endif
