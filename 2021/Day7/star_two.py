import timeit

start = timeit.default_timer()

def calc_crab_fuel(distance):
	fuel = 0
	for i in range(1, distance + 1):
		fuel += i
	return fuel

crabs = []

with open("input.txt") as fp:
	for line in fp:
		crabs = list(map(int, line.split(",")))

fuel = 0
fuel2 = 0
avg = round(sum(crabs) / len(crabs))
avg2 = int(sum(crabs) / len(crabs))
for crab in crabs:
	fuel += calc_crab_fuel(abs((avg) - crab))
for crab in crabs:
	fuel2 += calc_crab_fuel(abs((avg2) - crab))

if fuel < fuel2:
	print(fuel)
else:
	print(fuel2)

stop = timeit.default_timer()
print('Time: ', stop - start)