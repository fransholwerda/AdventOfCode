value = 0

def garbage(inp, i):
	global value
	while inp[i] != '>':
		if inp[i] == '!':
			i += 1
		else:
			value += 1
		i += 1
	return i

def group(inp, i):
	global value
	while inp[i] != '}':
		if inp[i] == '!':
			i += 1
		elif inp[i] == '{':
			i = group(inp, i + 1)
		elif inp[i] == '<':
			i = garbage(inp, i + 1)
		if (i + 1) < len(inp):
			i += 1
	return i

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

line = lines[0]
group(line, 0)
print(value)
