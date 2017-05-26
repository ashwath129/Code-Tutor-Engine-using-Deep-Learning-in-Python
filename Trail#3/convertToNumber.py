import json
def number(word):
	if word == "ArrayDecl":
		return 1
	elif word == "ArrayRef":
		return 	2
	elif word == "Assignment":
		return 3
	elif word == "BinaryOp":
		return 4
	elif word == "Break":
		return 5
	elif word == "Case":
		return 6
	elif word == "Cast":
		return 7
	elif word == "Compound":
		return 8
	elif word == "CompoundLiteral":
		return 9
	elif word == "Constant":
		return 10 
	elif word == "Continue":
		return 11
	elif word == "Decl":
		return 12
	elif word == "DeclList":
		return 13
	elif word == "Default":
		return 14
	elif word == "DoWhile":
		return 15
	elif word == "EllipsisParam":
		return 16
	elif word == "EmptyStatement":
		return 17
	elif word == "Enum":
		return 18
	elif word == "Enumerator":
		return 19
	elif word == "EnumeratorList":
		return 20
	elif word == "ExprList":
		return 21
	elif word == "Pragma":
		return 22
	elif word == "For":
		return 23
	elif word == "FuncCall":
		return 24
	elif word == "FuncDecl":
		return 25
	elif word == "FuncDef":
		return 26
	elif word == "Goto":
		return 27
	elif word == "ID":
		return 28
	elif word == "IdentifierType":
		return 29
	elif word == "InitList":
		return 30
	elif word == "Label":
		return 31
	elif word == "NamedInitializer":
		return 32
	elif word == "ParamList":
		return 33
	elif word == "PtrDecl":
		return 34
	elif word == "Return":
		return 35
	elif word == "Struct":
		return 36
	elif word == "StructRef":
		return 37
	elif word == "Switch":
		return 38
	elif word == "TernaryOp":
		return 39
	elif word == "TypeDecl":
		return 40
	elif word == "Typedef":
		return 41
	elif word == "Typename":
		return 42
	elif word == "UnaryOp":
		return 43
	elif word == "Union":
		return 44
	elif word == "While":
		return 45
	elif word == "If":
		return 46
	else:
		return 0

def convert(filename="Sequence.txt"):
	sequence = []
	with open('AST_file.txt') as fp:
		for line in fp:
		    i = number(line.rstrip())
		    if i==0:
		    	print(line.strip())
		    sequence.append(i)
		    
	print(len(sequence))
	Sequence_file = open(filename, "a")
	json.dump(sequence, Sequence_file)
	Sequence_file.write("\n")
	Sequence_file.close()
