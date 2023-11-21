depth = 0
value = 0

def garbage(inp, i):
	while inp[i] != '>':
		if inp[i] == '!':
			i += 1
		i += 1
	return i

def group(inp, i):
	global depth
	global value
	depth += 1
	while inp[i] != '}':
		if inp[i] == '!':
			i += 1
		elif inp[i] == '{':
			value += depth
			i = group(inp, i + 1)
		elif inp[i] == '<':
			i = garbage(inp, i + 1)
		if (i + 1) < len(inp):
			i += 1
	depth -= 1
	return i

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

line = lines[0]
group(line, 0)
print(value)
