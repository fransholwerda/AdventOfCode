from math import sqrt, ceil

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

input_number = int(lines[0])
side_size = ceil(sqrt(input_number))
corner_number = pow(side_size, 2) # The corner with the largest number

prev_corner = corner_number - (side_size - 1) # The corner with the second largest number
distance_from_prev_corner = abs(prev_corner - input_number)
xy_home = ceil(side_size / 2)
if (side_size % 2 == 1):
	xy_home -= 1
steps_from_home = xy_home + abs(xy_home - distance_from_prev_corner)

print(steps_from_home)