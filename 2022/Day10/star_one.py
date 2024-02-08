def check_cycle(cycle, x, signal_strength):
	if cycle >= 20 and (cycle - 20) % 40 == 0:
		signal_strength.append(x * cycle)

with open("input.txt", 'r') as fd:
	inp = fd.readlines()

signal_strength = []
x = 1
cycle = 1
for line in inp:
	line = line.strip().split(' ')
	check_cycle(cycle, x, signal_strength)
	if line[0] == 'addx':
		cycle += 1
		check_cycle(cycle, x, signal_strength)
		x += int(line[1])
	cycle += 1

print(sum(signal_strength))