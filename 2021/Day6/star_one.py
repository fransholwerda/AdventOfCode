fish = []

def dawn_of_a_new_day(days, fish):
	for i in range(0, days):
		count = len(fish)
		for i in range(0, count):
			if fish[i] == 0:
				fish[i] = 6
				fish.append(8)
			else:
				fish[i] -= 1
			i += 1

def total_fish(fish):
	count = 0
	for i in range(0, len(fish)):
		count += 1
	return count

with open("input.txt", "r") as fd:
	for line in fd:
		fish = list(map(int, line.split(",")))
dawn_of_a_new_day(80, fish)
print(total_fish(fish))