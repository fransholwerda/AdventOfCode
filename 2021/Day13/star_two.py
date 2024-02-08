from numpy import zeros

def fold_coordinates(coordinates, high_x, high_y, fold, axis):
	if axis == 'x':
		for y in range(0, high_y):
			for x in range(fold, high_x):
				if coordinates[y][x] == 1:
					coordinates[y][fold - (x - fold)] = 1
		high_x = fold
	elif axis == 'y':
		for y in range(fold, high_y):
			for x in range(0, high_x):
				if coordinates[y][x] == 1:
					coordinates[fold - (y - fold)][x] = 1
		high_y = fold
	return coordinates, high_x, high_y


inp = []
with open("input.txt", 'r') as fd:
	temp = fd.read()
	inp = temp.splitlines()

high_x = 0
high_y = 0
for line in inp:
	if line.split(',')[0].isdecimal():
		if int(line.split(',')[0]) > high_x:
			high_x = int(line.split(',')[0])
		if int(line.split(',')[1]) > high_y:
			high_y = int(line.split(',')[1])
high_x += 1
high_y += 1

coordinates = zeros((high_y, high_x))

instructions = []
for line in inp:
	if line.split(',')[0].isdecimal():
		coordinates[int(line.split(',')[1])][int(line.split(',')[0])] = 1
	if 'y' in line:
		instructions.append('y' + line[line.index('=')+1:])
	if 'x' in line:
		instructions.append('x' + line[line.index('=')+1:])

for instruction in instructions:
	coordinates, high_x, high_y = fold_coordinates(coordinates, high_x, high_y, int(instruction[1:]), instruction[0])

for y in range(0, high_y):
	for x in range(0, high_x):
		if coordinates[y][x] == 0:
			print('.', end='')
		else:
			print('#', end='')
	print()
