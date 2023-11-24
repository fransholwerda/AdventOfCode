def knot_hash(steps, list_size, rounds):
	arr = list(range(list_size))
	pos = 0
	skip = 0
	for _ in range(rounds):
		for move in steps:
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
	return arr

lines = []
with open("test_input.txt", 'r') as fd:
	lines = fd.readlines()

ascii = [ord(char) for char in lines[0]] + [17,31,73,47,23]
sparse_hash = knot_hash(ascii, 256, 64)
dense_hash = []
for i in range(0, 256, 16):
	xor = sparse_hash[i]
	for j in range(1, 16):
		xor ^= sparse_hash[i+j]
	dense_hash.append(xor)

final_hash = [format(number, '02x') for number in dense_hash]
answer = ''.join(final_hash)
print(answer)