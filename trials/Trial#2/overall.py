import ASTProducer
import convertToNumber
import predictor
import trainer
for i in range(1, 21):
	filename = "training_sets/dectobin/dtob"+str(i)+".c"
	ASTProducer.produce(filename)
	convertToNumber.convert()
trainer.train()
test_filename = "test_sets/dectobin/testdtob1.c"
ASTProducer.produce(test_filename)
convertToNumber.convert("InputSequence.txt")
