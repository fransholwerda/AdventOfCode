lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

max_red = 12
max_green = 13
max_blue = 14
answer = 0
for line in lines:
	data = line.strip().split(": ")
	game_id = int(data[0][5:])
	bad_game = False
	for cube_set in data[1].split('; '):
		for cube in cube_set.split(", "):
			if "red" in cube:
				temp = cube.strip(" red")
				if int(temp) > max_red:
					bad_game = True
			if "green" in cube:
				temp = cube.strip(" green")
				if int(temp) > max_green:
					bad_game = True
			if "blue" in cube:
				temp = cube.strip(" blue")
				if int(temp) > max_blue:
					bad_game = True
	if bad_game == False:
		answer += game_id

print(answer)