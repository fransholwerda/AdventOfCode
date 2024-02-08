with open("input.txt", 'r') as fd:
	inp = fd.readlines()

grid = []
for line in inp:
	line = line.strip()
	grid.append([int(line[i]) for i in range(len(line))])

visible_tree_grid = [[0 for i in range(len(inp))] for j in range(len(inp[0].strip()))]

# from left to right
for y in range(len(grid)):
	highest_tree = -1
	for x in range(len(grid[0])):
		if highest_tree == 9:
			break
		if grid[y][x] > highest_tree:
			highest_tree = grid[y][x]
			visible_tree_grid[y][x] = 1

# from right to left
for y in range(len(grid) - 1, -1, -1):
	highest_tree = -1
	for x in range(len(grid[0]) - 1, -1, -1):
		if highest_tree == 9:
			break
		if grid[y][x] > highest_tree:
			highest_tree = grid[y][x]
			visible_tree_grid[y][x] = 1

# from top to bottom
for x in range(len(grid[0])):
	highest_tree = -1
	for y in range(len(grid)):
		if highest_tree == 9:
			break
		if grid[y][x] > highest_tree:
			highest_tree = grid[y][x]
			visible_tree_grid[y][x] = 1

# from bottom to top
for x in range(len(grid[0]) - 1, -1, -1):
	highest_tree = -1
	for y in range(len(grid) - 1, -1, -1):
		if highest_tree == 9:
			break
		if grid[y][x] > highest_tree:
			highest_tree = grid[y][x]
			visible_tree_grid[y][x] = 1

visible_trees = 0
for row in visible_tree_grid:
	print(row)
	for tree in row:
		if tree == 1:
			visible_trees += 1

print(visible_trees)