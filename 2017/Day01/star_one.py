lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

total = 0
first = -1
for digit in lines[0]:
	if first == -1:
		first = digit
	else:
		if digit == first:
			total += int(digit)
	first = digit
if first == lines[0][0]:
	total += int(first)
print(total)