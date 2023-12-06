def run_next_picosecond(firewall):
	for layer in firewall:
		if (len(layer) > 0):
			if layer[0] == 0:
				layer[1] = 1
			elif layer[0] == layer[2] - 1:
				layer[1] = -1
			layer[0] += layer[1]
	return firewall

def run_through_firewall(firewall):
	packet_pos = 0
	layers_cought = []
	while packet_pos < len(firewall):
		if len(firewall[packet_pos]) > 0:
			if firewall[packet_pos][0] == 0:
				layers_cought.append(packet_pos)
		firewall = run_next_picosecond(firewall)
		packet_pos += 1
	return layers_cought

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

firewall = []
layer_pos = 0
line_pos = 0
while layer_pos <= int(lines[-1].split(": ")[0]):
	layer = []
	if (layer_pos == int(lines[line_pos].split(": ")[0])):
		layer.append(0)
		layer.append(1)
		layer.append(int(lines[line_pos].strip().split(": ")[1]))
		line_pos += 1
	firewall.append(layer)
	layer_pos += 1

layers_cought = run_through_firewall(firewall)

answer = 0
for layer in layers_cought:
	answer += (layer * firewall[layer][2])

print(answer)