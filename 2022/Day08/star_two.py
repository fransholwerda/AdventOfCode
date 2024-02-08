def left_to_right(start_x, y, tree_height, grid):
	visible_trees = 0
	for x in range(start_x + 1, len(grid[0])):
		if grid[y][x] < tree_height:
			visible_trees += 1
		elif grid[y][x] >= tree_height:
			visible_trees += 1
			return visible_trees
		else:
			return visible_trees
	return visible_trees

def right_to_left(start_x, y, tree_height, grid):
	visible_trees = 0
	for x in range(start_x - 1, -1, -1):
		if grid[y][x] < tree_height:
			visible_trees += 1
		elif grid[y][x] >= tree_height:
			visible_trees += 1
			return visible_trees
		else:
			return visible_trees
	return visible_trees

def top_to_bot(start_y, x, tree_height, grid):
	visible_trees = 0
	for y in range(start_y + 1, len(grid)):
		if grid[y][x] < tree_height:
			visible_trees += 1
		elif grid[y][x] >= tree_height:
			visible_trees += 1
			return visible_trees
		else:
			return visible_trees
	return visible_trees

def bot_to_top(start_y, x, tree_height, grid):
	visible_trees = 0
	for y in range(start_y - 1, -1, -1):
		if grid[y][x] < tree_height:
			visible_trees += 1
		elif grid[y][x] >= tree_height:
			visible_trees += 1
			return visible_trees
		else:
			return visible_trees
	return visible_trees

def get_tree_score(x, y, grid):
	tree_height = grid[y][x]
	right = left_to_right(x, y, tree_height, grid)
	left = right_to_left(x, y, tree_height, grid)
	bot = top_to_bot(y, x, tree_height, grid)
	top = bot_to_top(y, x, tree_height, grid)
	score = right * left * bot * top
	return (score)

with open("input.txt", 'r') as fd:
	inp = fd.readlines()

grid = []
for line in inp:
	line = line.strip()
	grid.append([int(line[i]) for i in range(len(line))])

tree_grid = [[0 for i in range(len(inp))] for j in range(len(inp[0].strip()))]

highest_scenic_score = 0
for y in range(len(grid)):
	for x in range(len(grid[0])):
		tree_grid[y][x] = get_tree_score(x, y, grid)
		if tree_grid[y][x] > highest_scenic_score:
			highest_scenic_score = tree_grid[y][x]

print(highest_scenic_score)