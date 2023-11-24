def create_tree(connections, start):
	tree = {start: set()}
	visited = set()

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

connections = {}
for line in lines:
	data = line.strip().split(" <-> ")
	key = int(data[0])
	value = [int(pipe) for pipe in data[1].split(', ')]
	connections[key] = value

tree_zero = create_tree(connections, 0)
answer = len(tree_zero)
print(answer)
