def create_tree(connections, start):
	tree = {start: set()}

	def climb_tree(node):
		visited.add(node)
		for neighbor in connections[node]:
			if neighbor not in visited:
				tree[node].add(neighbor)
				tree[neighbor] = set()
				climb_tree(neighbor)
	
	climb_tree(start)
	return tree

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

visited = set()
connections = {}
total_keys = 0
for line in lines:
	data = line.strip().split(" <-> ")
	key = int(data[0])
	value = [int(pipe) for pipe in data[1].split(', ')]
	connections[key] = value
	total_keys += 1

trees = []
pos = 0
while len(visited) < total_keys:
	while pos in visited:
		pos += 1
	tree = create_tree(connections, pos)
	trees.append(create_tree)

answer = len(trees)
print(answer)
