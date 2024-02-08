def add_pixel(screen, cycle, x, pos):
	height = int((cycle - 1) / 40)
	print(cycle,x,pos)
	if (cycle) % 40 == 1:
		screen.append([])
	if x - 1 == pos or x + 1 == pos or x == pos:
		screen[height].append('#')
	else:
		screen[height].append('.')
	if pos == 39:
		return 0
	else:
		return pos + 1

with open("input.txt", 'r') as fd:
	inp = fd.readlines()

screen = []
cycle = 1
x = 1
pos = 0
for line in inp:
	pos = add_pixel(screen, cycle, x, pos)
	line = line.strip().split(' ')
	if line[0] == 'addx':
		cycle += 1
		pos = add_pixel(screen, cycle, x, pos)
		x += int(line[1])
	cycle += 1

for row in screen:
	for char in row:
		print(char, end='')
	print()