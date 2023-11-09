lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

total = 0
for line in lines:
	number_array = line.split()
	i = 0
	while i < len(number_array):
		j = 0
		while j < len(number_array):
			if i != j:
				division = (float(number_array[i]) / float(number_array[j]))
				if (division).is_integer():
					total += division
			j += 1
		i += 1
print(int(total))