lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

answer = 0
for line in lines:
	data = line.strip().split(": ")
	game_id = int(data[0][5:])
	red = 0
	green = 0
	blue = 0
	for cube_set in data[1].split('; '):
		for cube in cube_set.split(", "):
			if "red" in cube:
				temp = cube.strip(" red")
				if int(temp) > red:
					red = int(temp)
			if "green" in cube:
				temp = cube.strip(" green")
				if int(temp) > green:
					green = int(temp)
			if "blue" in cube:
				temp = cube.strip(" blue")
				if int(temp) > blue:
					blue = int(temp)
	answer += (red * green * blue)

print(answer)