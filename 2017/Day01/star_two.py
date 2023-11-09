lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

total = 0
first_half = 0
second_half = int(len(lines[0]) / 2)
while (second_half < int(len(lines[0]))):
	if lines[0][first_half] == lines[0][second_half]:
		total += (int(lines[0][first_half]) * 2)
	first_half += 1
	second_half += 1
print(total)