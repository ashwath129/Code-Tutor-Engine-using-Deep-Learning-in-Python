import tensorflow as tf
import numpy as np
import json

def predict():

	#------------------------------------------------------------------------------------------------------------------------------------#
	
	#------------------------------------------STEP 1. PREPARE TEST SETS-----------------------------------------------------------------#
	
	#------------------------------------------------------------------------------------------------------------------------------------#
	
	test_input = []
	test_output = []
	
	# 1.1 Load the sequences into lists
	with open("InputSequence.txt") as fp:
		for line in fp:
			sequence = json.loads(line)
			length = len(sequence)						
			for i in range(length-1):					 
				test_input.append(sequence[:i+1])	
				test_output.append(sequence[i+1])
	
	maxlength = len(test_input[0])
	for i in test_input:
		l = len(i)
		if maxlength<l:
			maxlength = l

	for i in test_input:
		l = len(i)
		i+=([0,]*(maxlength-l))

	length = len(test_input)
	assert(length == len(test_output))
	test = np.reshape(test_input, (len(test_input), maxlength, 1))	

	#-------------------------------------------------------------------------------------------------------------------------------------#

	#-----------------------------------------------STEP 2. DESIGN THE RNN----------------------------------------------------------------#

	#-------------------------------------------------------------------------------------------------------------------------------------#

	# 2.1 Configure training data characteristics

	with tf.name_scope("inputs"):
		data = tf.placeholder(tf.float32, [None, maxlength, 1], name="training_x")	
		target = tf.placeholder(tf.float32, [None, 68], name="training_y")	#---> 1 - no. of dimensions, 68 - number of classes

	num_hidden = 600														#----> Number of hidden cells/hidden layers

	# 2.2 Configure the LSTM cell

	cell = tf.nn.rnn_cell.LSTMCell(num_hidden, state_is_tuple=True)			#---> tf.nn.rnn_cell.LSTMCell.__init__(num_units, input_size=None, use_peepholes=False, cell_clip=None, initializer=None, num_proj=None, num_unit_shards=1, num_proj_shards=1, forget_bias=1.0, state_is_tuple=False, activation=tanh)

	# 2.3 Configure the RNN for the LSTM

	val, state = tf.nn.dynamic_rnn(cell, data, dtype=tf.float32)			#---> tf.nn.dynamic_rnn(cell, inputs, sequence_length=None, initial_state=None, dtype=None, parallel_iterations=None, swap_memory=False, time_major=False, scope=None)

	# 2.4 Convert the result to desired form

	val = tf.transpose(val, [1, 0, 2])
	last = tf.gather(val, int(val.get_shape()[0])-1)

	# 2.5 Allocate space for weights and biases

	weights = tf.Variable(tf.truncated_normal([num_hidden, int(target.get_shape()[1])]), name="weights")	
	biases = tf.Variable(tf.constant(0.1, shape=[target.get_shape()[1]]), name="biases")
	
	# 2.6 Configure the Prediction function

	prediction = tf.nn.softmax(tf.matmul(last, weights)+biases, name="prediction")	#---> tf.nn.softmax(logits, dim=-1, name=None)

	# 2.7 Calculate cross entropy

	cross_entropy = -tf.reduce_sum(target * tf.log(prediction), name="cross_entropy")	#---> tf.reduce_sum(input_tensor, axis=None, keep_dims=False, name=None, reduction_indices=None) Calculates the sum of the tensor, Adding the log term helps in penalizing the model more if it is terribly wrong and very little when the prediction is close to the target

	# 2.9 Configure the initialize all variables function

	init_op = tf.initialize_all_variables()


	#-------------------------------------------------------------------------------------------------------------------------------------#
	
	#-----------------------------------------------STEP 3. PREDICT-----------------------------------------------------------------------#
	
	#-------------------------------------------------------------------------------------------------------------------------------------#
	
	# 3.1 Create a tensor flow session
	sess = tf.Session()
	sess.run(init_op)

	# 3.2 Create the graph summary writer
	writer = tf.train.SummaryWriter("logs/",sess.graph)

	# 3.3 Load the syntax check matrix into list of lists
	matrix=[]
	matrixFile = open("matrix.txt", "r")
	for line in matrixFile:
		matrix.append(json.loads(line))
	
	# 3.4 Weights file should exist. Load weights (which we had written in lists form) and convert into numpy array
	weights=[]
	WeightsFile = open("weights.txt", "r")
	for line in WeightsFile:
		weights.append(np.asarray(json.loads(line)))
	
	for i in range(len(weights)):
		print(weights[i])
	i=0
	print("Before assigning: ")
	for v in tf.trainable_variables():
		print(sess.run(v))
		
	# 3.5 Assign the loaded weights to the trainable variables
	print("After assigning: ")
	for v in tf.trainable_variables():
		print(sess.run(v.assign(weights[i])))
		i=i+1
	
	# 3.5 Predict
	result=sess.run(prediction, {data: test})
	assert(length == len(result))
	
	# 3.6 Write results to result_file
	total=0;
	correct=0;
	predicted=[]
	result_file = open("result_file.txt", "w")
	previous = 0
	for i in range(0, length):
		result_file.write("Case "+str(i)+":\n")
		json.dump(result[i].tolist(), result_file)
		result_file.write("\n")
		"""maxi = max(result[i])
		result_file.write("Max probability is: "+str(maxi)+"\n")"""
		sublength = len(result[i])
		assert(sublength==68)
		"""if(i!=0):
			print("Syntax based shortlisting..")
			for j in range(0, sublength):
				if(matrix[previous][j]==1):
					print(j)
			copy_list = [x for k, x in enumerate(result[i]) if matrix[previous][k]==1]
			
		else:"""
		copy_list = list(result[i])
		copy_list.sort()
		print(result[i])
		print(copy_list)
		temp = []
		j=len(copy_list)-1
		print("Length of copy list is: "+str(j+1))
		count=0
		while(count<=4 and j>=0):
			indices = [k for k, x in enumerate(result[i]) if x==copy_list[j]]
			temp+=indices
			j = j-1
			count=count+1
		print(temp)
		if(len(temp)):
			previous=temp[0]					
		result_file.write("Classes with max probability: ")
		json.dump(temp, result_file)
		result_file.write("\n")
		predicted.append(temp)

	# 3.7 Calculate accuracy
	assert(len(predicted)==length)
	for i in range(0, length):
		if(test_output[i] in predicted[i]):
			correct+=1
		result_file.write(str(predicted[i])+" "+str(test_output[i])+"\n")

	accuracy = float(correct/length) * 100
	result_file.write("\nAccuracy is: "+str(accuracy))
	
	sess.close()
