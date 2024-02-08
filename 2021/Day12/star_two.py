def find_path(entry, caves, path):
	if entry == "end":
		return 1
	if entry == "start" and "start" in path:
		return 0
	if entry.islower():
		count = {}
		for cave in path.split(','):
			if cave.islower():
				if cave not in count:
					count[cave] = 0
				count[cave] += 1
		cave_double_counts = 0
		for cave in count.keys():
			if count[cave] > 2:
				return 0
			if count[cave] == 2:
				cave_double_counts += 1
			if cave_double_counts > 1:
				return 0			
	if entry == "start":
		answer = 0
		path = "start"
		for cave in caves[entry]:
			answer += find_path(cave, caves, path + ',' + cave)
		return answer
	answer = 0
	for cave in caves[entry]:
		answer += find_path(cave, caves, path + ',' + cave)
	return answer

inp = []
with open("input.txt", 'r') as fd:
	inp = fd.read().splitlines()

caves = {}
for line in inp:
	temp = line.split('-')
	if temp[0] not in caves:
		caves[temp[0]] = []
		caves[temp[0]].append(temp[1])
	else:
		caves[temp[0]].append(temp[1])
	if temp[1] not in caves:
		caves[temp[1]] = []
		caves[temp[1]].append(temp[0])
	else:
		caves[temp[1]].append(temp[0])

answer = find_path("start", caves, "")

print(answer)