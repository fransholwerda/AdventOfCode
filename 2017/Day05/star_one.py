lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

array = []
for line in lines:
	array.append(int(line))

steps = 0
cursor = 0
while cursor < len(array):
	if array[cursor] >= 3:
		array[cursor] -= 1
		cursor += array[cursor] + 1
	else:
		array[cursor] += 1
		cursor += array[cursor] - 1
	steps += 1
print(steps)