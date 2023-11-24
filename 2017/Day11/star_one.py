def hex_movement_distance(a, b):
	return (abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2])) // 2

lines = []
with open("input.txt", 'r') as fd:
	lines = fd.readlines()

x = 0
y = 0
z = 0
for dir in lines[0].split(','):
	if dir == 'n':
		y += 1
		z -= 1
	elif dir == 'ne':
		x += 1
		z -= 1
	elif dir == 'se':
		x += 1
		y -= 1
	elif dir == 's':
		y -= 1
		z += 1
	elif dir == 'sw':
		x -= 1
		z += 1
	elif dir == 'nw':
		x -= 1
		y += 1

a = [x,y,z]
b = [0,0,0]
answer = hex_movement_distance(a,b)

print(answer)