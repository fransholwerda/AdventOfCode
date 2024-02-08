with open("input.txt", 'r') as fd:
	inp = fd.read().splitlines()

score = 0
for line in inp:
	if line[0] == 'A':
		if line[2] == 'X':
			score += 1
			score += 3
		elif line[2] == 'Y':
			score += 2
			score += 6
		elif line[2] == 'Z':
			score += 3
			score += 0
	elif line[0] == 'B':
		if line[2] == 'X':
			score += 1
			score += 0
		elif line[2] == 'Y':
			score += 2
			score += 3
		elif line[2] == 'Z':
			score += 3
			score += 6
	elif line[0] == 'C':
		if line[2] == 'X':
			score += 1
			score += 6
		elif line[2] == 'Y':
			score += 2
			score += 0
		elif line[2] == 'Z':
			score += 3
			score += 3

print(score);