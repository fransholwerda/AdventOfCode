def isDigit(c):
	return c >= '0' and c <= '9'

def isNumber(i, line):
	str_numbers = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
	for str_number in range(0, len(str_numbers)):
		if str_numbers[str_number] in line[i:i + len(str_numbers[str_number])]:
			return str(str_number + 1)
	return '-1'

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
		elif isNumber(i, line) != '-1':
			first_digit = isNumber(i, line)
		if isDigit(line[j]):
			last_digit = line[j]
		elif isNumber(j, line) != '-1':
			last_digit = isNumber(j, line)
		if first_digit == '-1':
			i += 1
		if last_digit == '-1':
			j -= 1
		if first_digit != '-1' and last_digit != '-1':
			break
	number = int(first_digit + last_digit)
	answer += number
print(answer)