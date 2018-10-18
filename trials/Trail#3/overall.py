import ASTProducer
import convertToNumber
import predictor
import trainer
for i in range(1, 21):
	filename = "training_sets/dectobin/dtob"+str(i)+".c"
	ASTProducer.produce(filename)
	convertToNumber.convert()
