def valid_word(word, words_used):
	for word_check in words_used:
		if len(word) != len(word_check):
			continue
		else:
			anagram = True
			for letter in word:
				if word.count(letter) != word_check.count(letter):
					anagram = False
			if anagram:
				return False 
	return True

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

valid_passphrases = 0
for line in lines:
	words_used = []
	valid = True
	for word in line.split():
		if valid_word(word, words_used) == False:
			valid = False
		words_used.append(word)
	if valid:
		valid_passphrases += 1

print(valid_passphrases)