crabs = []

with open("input.txt") as fp:
	for line in fp:
		crabs = list(map(int, line.split(",")))

crabs.sort()
fuel = 0
for crab in crabs:
	fuel += abs(crab - (crabs[int(len(crabs) / 2)]))

print(fuel)