balls = []
bingos = []
bingo = []

with open("input.txt", "r") as fd:
	i = 0
	j = 0
	for line in fd:
		if i == 0:
			balls = line.split(",")
			balls = list(map(int, balls))
		elif i%6 - 2 == 0 and j == 0:
			j += 1
			bingo.append(list(map(int, line.split())))
		elif j == 1 or j == 2 or j == 3:
			j += 1
			bingo.append(list(map(int, line.split())))
		elif j == 4:
			j = 0
			bingo.append(list(map(int, line.split())))
			bingos.append(bingo)
			bingo = []
		i += 1

def find_bingo(balls, bingos):
	for ball in balls:
		for x in range(len(bingos)):
			for y in range(len(bingos[x])):
				for z in range(len(bingos[x][y])):
					if bingos[x][y][z] == ball:
						bingos[x][y][z] = -1
					z += 1
				y += 1
			x += 1
		for x in range(len(bingos)):
			for z in range(len(bingos[x][0])):
				if bingos[x][0][z] == -1 and bingos[x][1][z] == -1 and bingos[x][2][z] == -1 and bingos[x][3][z] == -1 and bingos[x][4][z] == -1:
					return x, ball
			for y in range(len(bingos[x])):
				if bingos[x][y][0] == -1 and bingos[x][y][1] == -1 and bingos[x][y][2] == -1 and bingos[x][y][3] == -1 and bingos[x][y][4] == -1:
					return x, ball
				y += 1
			x += 1

x, ball = find_bingo(balls, bingos)
sum = 0
for row in bingos[x]:
	for number in row:
		if number >= 0:
			sum += number
answer = sum * ball
print(answer)