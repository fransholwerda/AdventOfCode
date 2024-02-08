with open("input.txt", 'r') as fd:
	inp = fd.readlines()

sections = []
for line in inp:
	line = line.strip()
	split = line.split(',')
	section_1 = split[0].split('-')
	section_2 = split[1].split('-')
	section_1 = [eval(i) for i in section_1]
	section_2 = [eval(i) for i in section_2]
	sections.append([section_1, section_2])

result = 0
for pair in sections:
	if pair[0][0] >= pair[1][0] and pair[0][0] <= pair[1][1]:
		result += 1
	elif pair[0][1] >= pair[1][0] and pair [0][1] <= pair[1][1]:
		result += 1
	elif pair[1][0] >= pair[0][0] and pair[1][0] <= pair[0][1]:
		result += 1
	elif pair[1][1] >= pair[0][0] and pair[1][1] <= pair[0][1]:
		result += 1

print(result)