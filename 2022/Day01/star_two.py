with open("input.txt", 'r') as fd:
	inp = fd.read().split("\n\n")

for i in range(0, len(inp)):
	inp[i] = inp[i].split("\n")

results = []

for i in range(0, len(inp)):
	results.append(0)

for i in range(0, len(inp)):
	for number in inp[i]:
		results[i] += int(number)

result = 0
for i in range (0, 3):
	result += max(results)
	results.pop(results.index(max(results)))
print(result)