def compare(registers, data):
	if data[5] == ">":
		return int(data[2]) if registers[data[4]] > int(data[6]) else 0
	if data[5] == "<":
		return int(data[2]) if registers[data[4]] < int(data[6]) else 0
	if data[5] == "==":
		return int(data[2]) if registers[data[4]] == int(data[6]) else 0
	if data[5] == ">=":
		return int(data[2]) if registers[data[4]] >= int(data[6]) else 0
	if data[5] == "<=":
		return int(data[2]) if registers[data[4]] <= int(data[6]) else 0
	if data[5] == "!=":
		return int(data[2]) if registers[data[4]] != int(data[6]) else 0
	return 0

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

answer = -99999999
registers = {}
for line in lines:
	data = line.strip().split()
	if data[0] not in registers:
		registers[data[0]] = 0
	if data[4] not in registers:
		registers[data[4]] = 0
	if data[1] == "inc":
		registers[data[0]] += compare(registers, data)
	else:
		registers[data[0]] -= compare(registers, data)
	if registers[data[0]] > answer:
		answer = registers[data[0]]

for register in registers:
	if registers[register] > answer:
		answer = registers[register]

print(answer)