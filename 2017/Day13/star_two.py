lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

firewall = {}
for line in lines:
	data = line.strip().split(": ")
	firewall[int(data[0])] = int(data[1])

picosecond = 0
done = False
while not done:
	done = True
	for layer in firewall.keys():
		if (layer + picosecond) % (2 * firewall[layer] - 2) == 0:
			done = False
			picosecond += 1
			break

print(picosecond)