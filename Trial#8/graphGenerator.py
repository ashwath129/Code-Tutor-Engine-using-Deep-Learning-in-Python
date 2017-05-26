import json
def generate():
	matrix = []
	for i in range(1,69):
		temp = []
		for j in range(1,69):
			temp.append(0)
		matrix.append(temp)
	print(len(matrix))
	print(len(matrix[0]))
	with open("Sequence.txt", "r") as sequenceFile:
		for line in sequenceFile:
			sequence = json.loads(line)
			length = len(sequence)
			for i in range(length-1):
				if(sequence[i+1]==0):
					print(sequence)
				matrix[sequence[i]][sequence[i+1]]=1
	matrixFile = open("matrix.txt", "w")
	for i in range(0,68):
		json.dump(matrix[i], matrixFile)
		matrixFile.write("\n")
