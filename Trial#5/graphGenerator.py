import json
def generate():
	matrix = []
	for i in range(1,48):
		temp = []
		for j in range(1,48):
			temp.append(0)
		matrix.append(temp)
	print(len(matrix))
	print(len(matrix[0]))
	with open("Sequence.txt", "r") as sequenceFile:
		for line in sequenceFile:
			sequence = json.loads(line)
			length = len(sequence)
			for i in range(length-1):
				matrix[sequence[i]][sequence[i+1]]=1
	matrixFile = open("matrix.txt", "a")
	for i in range(1,47):
		json.dump(matrix[i], matrixFile)
		matrixFile.write("\n")
