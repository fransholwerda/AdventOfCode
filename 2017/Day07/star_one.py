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

result = ""
for key in all_keys:
	found = False
	for second_key in tree:
		if key in tree[second_key]:
			found = True
	if found == False:
		result = key

print(result)