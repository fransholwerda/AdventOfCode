lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

list_size = 256
arr = list(range(list_size))
steps = lines[0].split(',')
pos = 0
skip = 0
for step in steps:
	move = int(step)
	if move > 1:
		end = (pos+move)%(list_size)
		if pos < end:
			arr[pos:end] = reversed(arr[pos:end])
		else:
			temp = list(reversed(arr[pos:] + arr[:end]))
			arr[pos:] = temp[:list_size - pos]
			arr[:end] = temp[list_size - pos:]
	pos = (pos + move + skip) % list_size
	skip += 1

answer = arr[0] * arr[1]
print(answer)
