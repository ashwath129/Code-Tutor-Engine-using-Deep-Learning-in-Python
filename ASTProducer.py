import os
import sys
from pycparser import c_parser, c_ast
def PrintPreorder(node, AST_file):
	children = (list)(node.children())
	for (child_name, child) in children:
		name = child.__class__.__name__
		if(name=="BinaryOp" or name=="UnaryOp"):
			name=child.op
		AST_file.write(name+"\n")
		PrintPreorder(child, AST_file)

def produce(fileName):
	ProgramFileName = fileName
	command = "gcc "+ProgramFileName+" -E -std=c99 -I utils/fake_libc_include > preprocessed.txt"
	os.system(command)
	PreprocessedFile = open("preprocessed.txt")
	Program = PreprocessedFile.read()
	diff = Program.count('{')-Program.count('}')
	while(diff):
		Program = Program+"\n}"
		diff = diff-1
	PreprocessedFile.close()
	#os.system("rm "+pwd+"preprocessed.txt")
	parser = c_parser.CParser()
	ast = parser.parse(Program, filename='<none>')
	AST_file = open("AST_file.txt", "w")
	PrintPreorder(ast, AST_file)
	ast.show()
	AST_file.close()
