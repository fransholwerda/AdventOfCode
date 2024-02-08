with open("input.txt", "r") as file:
	lines = file.readlines()

instructions = lines[0].split(', ')
x = 0
y = 0
direction = 'n'
for instr in instructions:
	if direction == 'n':
		if instr[0] == 'R':
			x += int(instr[1:])
			direction = 'e'
		else:
			x -= int(instr[1:])
			direction = 'w'
	elif direction == 'e':
		if instr[0] == 'R':
			y -= int(instr[1:])
			direction = 's'
		else:
			y += int(instr[1:])
			direction = 'n'
	elif direction == 's':
		if instr[0] == 'R':
			x -= int(instr[1:])
			direction = 'w'
		else:
			x += int(instr[1:])
			direction = 'e'
	elif direction == 'w':
		if instr[0] == 'R':
			y += int(instr[1:])
			direction = 'n'
		else:
			y -= int(instr[1:])
			direction = 's'

print(abs(x) + abs(y))