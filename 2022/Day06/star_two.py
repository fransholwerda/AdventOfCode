def check_unique(marker):
	print(marker)
	for char in marker:
		if marker.count(char) > 1:
			return False
	return True

with open("input.txt", 'r') as fd:
	inp = fd.readlines()

marker = []
for i in range(len(inp[0])):
	if len(marker) < 14:
		marker.append(inp[0][i])
	else:
		marker.pop(0)
		marker.append(inp[0][i])
	if len(marker) == 14:
		if check_unique(marker) == True:
			print(i+1)
			break