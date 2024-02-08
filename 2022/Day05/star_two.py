def get_index_stacknumbers(lines):
	for i in range(len(lines)):
		if lines[i][1] == '1':
			return i

def create_stacks(line):
	stacks = []
	inp[index_stacknumber] = inp[index_stacknumber].replace(' ', '').strip()
	for i in range(len(inp[index_stacknumber])):
		stacks.append([])
	return stacks

def fill_stacks(stacks, inp, index_stacks):
	for i in range(index_stacknumber - 1, -1, -1):
		for j in range(len(stacks)):
			if inp[i][(1 + (j * 4))] != ' ':
				stacks[j].append(inp[i][(1 + (j * 4))])

def move_crates(stacks, inp, index_stacks):
	for i in range (index_stacks + 2, len(inp)):
		instr = inp[i].replace("move ", "").replace(" from ", ",").replace(" to ", ",").strip().split(',')
		for j in range(int(instr[0]), 0, -1):
			frm = int(instr[1]) - 1
			to = int(instr[2]) - 1
			stacks[to].append(stacks[frm][len(stacks[frm]) - 1 - (j-1)])
			stacks[frm].pop(len(stacks[frm]) - 1 - (j-1))

with open("input.txt", 'r') as fd:
	inp = fd.readlines()

index_stacknumber = get_index_stacknumbers(inp)
stacks = create_stacks(inp[index_stacknumber])
fill_stacks(stacks, inp, index_stacknumber)
move_crates(stacks, inp, index_stacknumber)

for stack in stacks:
	print(stack[len(stack) - 1], end='')
print()
