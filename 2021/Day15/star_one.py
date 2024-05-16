from heapq import heappop, heappush

def update_neighbors(pqueue, grid, dgrid):
	vector = heappop(pqueue)[1]
	x0 = vector[0][0]
	y0 = vector[0][1]
	x1 = vector[1][0]
	y1 = vector[1][1]
	distance = dgrid[y0][x0] + grid[y1][x1]
	if distance < dgrid[y1][x1]:
		dgrid[y1][x1] = distance
		if x1-1 > 0 and not (x1-1 == x0 and y1 == y0):
			heappush(pqueue, (x1-1+y1, ((x1,y1),(x1-1, y1))))
		if y1-1 > 0 and not (x1 == x0 and y1-1 == y0):
			heappush(pqueue, (x1+y1-1, ((x1,y1),(x1, y1-1))))
		if x1+1 < len(grid[0]) and not (x1+1 == x0 and y1 == y0):
			heappush(pqueue, (x1+1+y1, ((x1,y1),(x1+1, y1))))
		if y1+1 < len(grid) and not (x1 == x0 and y1+1 == y0):
			heappush(pqueue, (x1+y1+1, ((x1,y1),(x1, y1+1))))
	return (pqueue, dgrid)

def dijkstra(grid):
	dgrid = [[2000000000 for digit in numbers] for numbers in grid]
	dgrid[0][0] = 0
	pqueue = []
	heappush(pqueue, (1,((0,0),(0,1))))
	heappush(pqueue, (1,((0,0),(1,0))))

	while len(pqueue) > 0:
		pqueue, dgrid = update_neighbors(pqueue, grid, dgrid)
	
	return dgrid

inp = []
with open("input.txt", 'r') as fd:
	temp = fd.read()
	inp = temp.splitlines()

grid = [[int(digit) for digit in numbers] for numbers in inp]

dgrid = dijkstra(grid)
print(dgrid[len(dgrid)-1][len(dgrid[0])-1])