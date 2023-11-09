from math import sqrt, ceil, floor

def calculate_surrounding_area(Matrix, x, y):
	total = 0
	for i in range(-1, 2):
		total += Matrix[y - 1][x + i]
	total += Matrix[y][x - 1]
	total += Matrix[y][x + 1]
	for i in range(-1, 2):
		total += Matrix[y + 1][x + i]
	if total == 0:
		total = 1
	return total

def find_first_larger_value(input_value):
	size = ceil(sqrt(input_value))
	Matrix = [[0 for x in range(size)] for y in range(size)] 
	x = int(size / 2)
	y = int(size / 2)

	cursor_value = 1
	Matrix[y][x] = cursor_value
	steps = 2
	x_sign = 1
	y_sign = -1
	while cursor_value < input_value:
		i = 0
		while i < steps:
			cursor_value = calculate_surrounding_area(Matrix, x, y)
			if cursor_value > input_value:
				return cursor_value
			Matrix[y][x] = cursor_value
			if i != steps - 1:
				x += x_sign
			i += 1
		i = 0
		while i < steps:
			cursor_value = calculate_surrounding_area(Matrix, x, y)
			if cursor_value > input_value:
				return cursor_value
			Matrix[y][x] = cursor_value
			if i != steps - 1:
				y += y_sign
			i += 1
		x_sign = -x_sign
		y_sign = -y_sign
		steps += 1

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

input_value = int(lines[0])
result = find_first_larger_value(input_value)
print(result)
