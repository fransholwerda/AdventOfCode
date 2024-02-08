def search(array, x1, y1, x2, y2):
	answer1 = -1
	answer2 = -1
	if x1 == x2 and y1 == y2:
		return 0
	if x1 < x2:
		answer1 = array[y1][x1] + search(array, x1+1, y1, x2, y2)
	if y1 < y2:
		answer2 = array[y1][x1] + search(array, x1, y1+1, x2, y2)
	if answer1 == -1 and answer2 != -1:
		return answer2
	if answer2 == -1 and answer1 != -1:
		return answer1
	if answer1 <= answer2:
		return answer1
	if answer2 <= answer1:
		return answer2

inp = []
with open("input.txt", 'r') as fd:
	temp = fd.read()
	inp = temp.splitlines()

array = []
for line in inp:
	temp = []
	for char in line:
		temp.append(int(char))
	array.append(temp)

for y in array:
	for x in y:
		print(x, end='')
	print()

answer = search(array, 0, 0, len(array[0]) - 1, len(array) - 1)

print("Answer:", answer)