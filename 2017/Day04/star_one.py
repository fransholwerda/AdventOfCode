lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

valid_passphrases = 0
for line in lines:
	words_used = []
	valid = True
	for word in line.split():
		if word in words_used:
			valid = False
		words_used.append(word)
	if valid:
		valid_passphrases += 1

print(valid_passphrases)