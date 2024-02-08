def char_score(char):
	if char.isupper():
		return (ord(char) - 38)
	else:
		return (ord(char) - 96)

with open("input.txt", 'r') as fd:
	inp = fd.readlines()

rucksacks = []
for rucksack in inp:
	rucksack = rucksack.strip()
	rucksacks.append((rucksack[0:int(len(rucksack)/2)], rucksack[int(len(rucksack)/2):]))

score = 0
for rucksack in rucksacks:
	for char in rucksack[0]:
		if char in rucksack[1]:
			score += char_score(char)
			break

print(score)