def char_score(char):
	if char.isupper():
		return (ord(char) - 38)
	else:
		return (ord(char) - 96)

with open("input.txt", 'r') as fd:
	inp = fd.readlines()

score = 0
for i in range(0, len(inp), 3):
	for char in inp[i]:
		if char in inp[i+1] and char in inp[i+2]:
			score += char_score(char)
			break

print(score)