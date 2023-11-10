lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

array = []
for line in lines:
	for number in line.split():
		array.append(int(number))

redistribution_cycle = 0
seen_arrays = []
done = False
while not done:
	seen_arrays.append(array.copy())
	bank = max(array)
	cursor = array.index(bank)
	array[cursor] = 0
	cursor += 1
	while bank > 0:
		if cursor >= len(array):
			cursor = 0
		array[cursor] += 1
		bank -= 1
		cursor += 1
	redistribution_cycle += 1
	if array in seen_arrays:
		done = True

print(redistribution_cycle)