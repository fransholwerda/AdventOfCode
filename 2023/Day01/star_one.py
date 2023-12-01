def isDigit(c):
	return c >= '0' and c <= '9'

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

answer = 0
for line in lines:
	i = 0
	j = len(line) - 1
	first_digit = '-1'
	last_digit = '-1'
	while True:
		if isDigit(line[i]):
			first_digit = line[i]
		if isDigit(line[j]):
			last_digit = line[j]
		if first_digit == '-1':
			i += 1
		if last_digit == '-1':
			j -= 1
		if first_digit != '-1' and last_digit != '-1':
			break
	number = int(first_digit + last_digit)
	answer += number
print(answer)