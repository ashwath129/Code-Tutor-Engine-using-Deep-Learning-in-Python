import ASTProducer
import convertToNumber
import predictor
import trainer
for i in range(1, 46):
	filename = "training_sets/digitSum/"+str(i)+".c"
	ASTProducer.produce(filename)
	convertToNumber.convert()
	print(filename)
