import os
import json
from pycparser import c_parser, c_ast
def CreateTree(ProgramFileName):
	command = "gcc "+ProgramFileName+" -E -std=c99 -I utils/fake_libc_include > preprocessed.txt"
	os.system(command)
	PreprocessedFile = open("preprocessed.txt")
	Program = PreprocessedFile.read()
	parser = c_parser.CParser()
	return parser.parse(Program, filename='<none>')
	
def initialize(node, vector, count_matrix, loop):
	if(node is not None):
		if(node.__class__.__name__ == "BinaryOp"): 	
			if(node.op == "+" or node.op == "-"):					#-----> Added or subtracted
				vector[1] += 1
			if(node.op == "*" or node.op == "/"):					#-----> Multiplied or divided
				vector[2] += 1
			children = (list)(node.children())
			for (child_name, child) in children:
				initialize(child, vector[:], count_matrix, loop)

		elif(node.__class__.__name__ == "FuncCall"):				#-----> Invoked as a parameter
			vector[3]+=1
			children = list(node.children())
			for(childname, child) in children:
				initialize(child, vector[:], count_matrix, loop)
		
		elif(node.__class__.__name__ == "If"):						#------> In an if statement
			vector[4]+=1
			childname, child = node.children()[0]
			initialize(child, vector[:], count_matrix, loop)
			vector[4]-=1
			remaining = (list)(node.children()[1:])
			for (childname, child) in remaining:
				initialize(child, vector[:], count_matrix, loop)
	
		elif(node.__class__.__name__ == "ArrayRef"):
			print("ArrayRef")
			subscript = node.subscript
			subscriptType = subscript.__class__.__name__
			if(subscriptType == "ID"):								#-----> As an array subscript
				vector[5]+=1
			initialize(subscript, vector[:], count_matrix, loop)
	
		elif(node.__class__.__name__ == "Decl"):
			t = node.type
			if(t.__class__.__name__ == "TypeDecl"):
				if(node.init is not None):
					vector[6]+=1
			children = list(node.children())
			for(childname, child) in children:
				initialize(child, vector[:], count_matrix, loop)
	
		elif(node.__class__.__name__ == "Assignment"):
			initialize(node.rvalue, vector[:], count_matrix, loop)
			if(node.lvalue.__class__.__name__ == "ID"):
				rvalue = node.rvalue
				rname = rvalue.__class__.__name__
				if(rname == "Constant"):							#-----> Defined by Constant
					vector[6] += 1
				if(rname == "BinaryOp"):
					if(rvalue.op == "+" or rvalue.op == "-"):		#-----> Defined by addition or subtraction	
						vector[7] += 1						
					if(rvalue.op == "*" or rvalue.op == "/"):		#-----> Defined by multiplication or division
						vector[8] += 1						
			initialize(node.lvalue, vector[:], count_matrix, loop)

		elif(node.__class__.__name__ == "While"):
			if(loop==0):											#-----> In a single level loop
				vector[9]+=1										
			elif(loop==1):											#-----> In a second level loop
				vector[10]+=1
			else:													#-----> In a third level or deeper loop
				vector[11]+=1
			initialize(node.cond, vector[:], count_matrix, loop+1)
			if(loop==0):
				vector[9]-=1
			elif(loop==1):
				vector[10]-=1
			else:
				vector[11]-=1
			initialize(node.stmt, vector[:], count_matrix, loop+1)
		
		elif(node.__class__.__name__ == "For"):
			if(loop==0):											#-----> In a single level loop
				vector[9]+=1
			elif(loop==1):											#-----> In a second level loop
				vector[10]+=1
			else:
				vector[11]+=1										#-----> In a third level or deeper loop
			initialize(node.cond, vector[:], count_matrix, loop+1)
			if(loop==0):
				vector[9]-=1
			elif(loop==1):
				vector[10]-=1
			else:
				vector[11]-=1
			if(node.init is not None):
				initialize(node.init, vector[:], count_matrix, loop+1)
			if(node.stmt is not None):
				initialize(node.stmt, vector[:], count_matrix, loop+1)
			if(node.next is not None):
				initialize(node.next, vector[:], count_matrix, loop+1)
		
		elif(node.__class__.__name__ == "ID"):						#------> Used
			vector[0]+=1
			if(not(node.name in count_matrix)):
				count_matrix[node.name] = [i-i for i in range(12)]
			for i in range(12):
				count_matrix[node.name][i] += vector[i]
				node.count_vector[i] = count_matrix[node.name][i]
	
		else:
			children = (list)(node.children())
			for (child_name, child) in children:
				initialize(child, vector[:], count_matrix, loop)
	return count_matrix
	
def run(ProgramFileName):
	ast = CreateTree(ProgramFileName)
	ast.show()
	CountMatrixFile = open("compareMatrices.txt", "a")
	raw_dict = initialize(ast, [i-i for i in range(12)], dict(), 0)
	matrix = list(raw_dict.values())
	json.dump(matrix, CountMatrixFile)
	CountMatrixFile.write("\n")
	CountMatrixFile.close()
	
