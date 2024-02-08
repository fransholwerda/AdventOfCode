with open("test_input.txt", "r") as file:
	lines = file.readlines()

instructions = lines[0].split(', ')
x = 0
y = 0
direction = 'n'
visited = [(0,0)]
for instr in instructions:
	continue
print(x,y)
print(abs(x) + abs(y))