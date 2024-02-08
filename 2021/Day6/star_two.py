fish = [0, 0, 0, 0, 0, 0, 0, 0, 0]

def dawn_of_a_new_day(days, fish):
	for i in range(0, days):
		temp = fish[0]
		for j in range(0, 8):
			fish[j] = fish[j + 1]
		fish[8] = temp
		fish[6] += temp

def total_fish(fish):
	count = 0
	for i in fish:
		count += i
	return count

with open("input.txt", "r") as fd:
	for line in fd:
		input = list(map(int, line.split(",")))
		for number in input:
			fish[number] += 1
dawn_of_a_new_day(256, fish)
print(total_fish(fish))