def find_path(entry, caves, path):
	if entry == "end":
		return 1
	if entry.islower():
		count = 0
		for cave in path.split(','):
			if entry == cave:
				count += 1
		if count > 1:
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