with open("input.txt", 'r') as fd:
	inp = fd.read().splitlines()

score = 0
for line in inp:
	if line[0] == 'A':
		if line[2] == 'X':
			score += 0
			score += 3
		elif line[2] == 'Y':
			score += 3
			score += 1
		elif line[2] == 'Z':
			score += 6
			score += 2
	elif line[0] == 'B':
		if line[2] == 'X':
			score += 0
			score += 1
		elif line[2] == 'Y':
			score += 3
			score += 2
		elif line[2] == 'Z':
			score += 6
			score += 3
	elif line[0] == 'C':
		if line[2] == 'X':
			score += 0
			score += 2
		elif line[2] == 'Y':
			score += 3
			score += 3
		elif line[2] == 'Z':
			score += 6
			score += 1

print(score);