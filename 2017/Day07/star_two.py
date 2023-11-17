def get_column_sum(tree, column):
	column_sum = tree[column][0]
	if len(tree[column]) > 1:
		i = 1
		while i < len(tree[column]):
			column_sum += get_column_sum(tree, tree[column][i])
			i += 1
	return column_sum

def columns_same_sum(columns):
	column_sum = columns[0]
	for column in columns:
		if column_sum != column:
			return False
	return True

def abberant_column_index(columns):
	column_sum = columns[0]
	if column_sum not in columns[1:]:
		return 0
	i = 0
	while i < len(columns):
		if columns[i] != column_sum:
			return i
		i += 1
	return -1

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

tree = {}
all_keys = []

for line in lines:
	data = line.split(" -> ")
	key = data[0].split(" ")[0]
	all_keys.append(key)
	value = int(data[0].split(" ")[1].strip()[1:-1])
	other_keys = []
	if len(data) > 1:
		other_keys = data[1].split(", ")
		other_keys[-1] = other_keys[-1].strip()
	total_value = []
	total_value.append(value)
	if len(other_keys) > 0:
		for other_key in other_keys:
			total_value.append(other_key)
	tree[key] = total_value

bottom = ""
for key in all_keys:
	found = False
	for second_key in tree:
		if key in tree[second_key]:
			found = True
	if found == False:
		bottom = key

done = False
current_key = bottom
abberant_value = -1
correct_value = -1
while not done:
	columns = []
	column_sums = []
	if len(tree[current_key]) > 1:
		i = 1
		while (i < len(tree[current_key])):
			columns.append(tree[current_key][i])
			column_sums.append(get_column_sum(tree, tree[current_key][i]))
			i += 1
	if columns_same_sum(column_sums):
		done = True
	else:
		next_key_index = abberant_column_index(column_sums)
		abberant_key = tree[current_key][next_key_index + 1]
		abberant_value = column_sums[next_key_index]
		if next_key_index == 0 and len(column_sums) > 1:
			correct_value = column_sums[1]
		else:
			correct_value = column_sums[0]
		current_key = tree[current_key][next_key_index + 1]

difference = abs(correct_value - abberant_value)
answer = tree[abberant_key][0] - difference
print(answer)