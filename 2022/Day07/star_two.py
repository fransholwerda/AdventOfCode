with open("input.txt", 'r') as fd:
	inp = fd.readlines()

dirTree = {}
currentDir = []
for line in inp:
	data = line.strip().split(' ')
	if data[1] == "cd":
		if data[2] == "/":
			currentDir.append(data[2])
			dirTree[data[2]] = 0
		elif data[2] == "..":
			currentDir.pop(len(currentDir) - 1)
		else:
			currentDir.append(currentDir[-1] + data[2] + '/')
	elif data[0] == "dir":
		if currentDir[-1] + data[1] not in dirTree:
			dirTree[currentDir[-1] + data[1] + '/'] = 0
	elif data[0].isnumeric():
		for dir in currentDir:
			dirTree[dir] += int(data[0])

totalSpace = 70000000
minimumRequiredSpace = 30000000
totalUsedSpace = dirTree['/']
currentSpace = totalSpace - totalUsedSpace
removeAtleast = minimumRequiredSpace - currentSpace

dirToRemove = "/"
for dir in dirTree:
	if dirTree[dir] >= removeAtleast and dirTree[dir] < dirTree[dirToRemove]:
		dirToRemove = dir

print(dirTree[dirToRemove])