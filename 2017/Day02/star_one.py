lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

checksum = 0
for line in lines:
	smallest = 9999999999
	biggest = -1
	for number in line.split():
		if int(number) > biggest:
			biggest = int(number)
		if int(number) < smallest:
			smallest = int(number)
	checksum += biggest - smallest
print(checksum)