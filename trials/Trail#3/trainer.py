import tensorflow as tf
import numpy as np
import json

def train():
	#-------------------------------------------------------------------------------------------------------------------------------------#

	#--------------------------------------STEP 1. PREPARE THE TRAINING AND TEST SETS-----------------------------------------------------#

	#-------------------------------------------------------------------------------------------------------------------------------------#

	input_data_list = []
	output_data_list = []
	test_input = []
	test_output = []

	# 1.1 Read the text file and load it as list of lists.

	with open('Sequence.txt') as fp:				#----> Open the file containing the sequence of numbers for all the training programs.
		for line in fp:								#----> Every line contains the sequence for one program.
			sequence = json.loads(line)				#----> Convert the text into list data type.
			length = len(sequence)						
			for i in range(length-1):				#----> The sequence [1, 2, 3, 4, 5] is split into the sequences [1] o/p 2, [1, 2] o/p 
				input_data_list.append(sequence[:i+1])	#----> 3, [1, 2, 3] o/p 4 and [1, 2, 3, 4] o/p 5.
				output_data_list.append(sequence[i+1])	

	with open("InputSequence.txt") as fp:
		for line in fp:
			sequence = json.loads(line)
			length = len(sequence)						
			for i in range(length-1):					 
				test_input.append(sequence[:i+1])	
				test_output.append(sequence[i+1])	


	# 1.2 Convert the input data from list of lists to 2D numpy array of fixed size

	maxlength = len(input_data_list[0])
	for i in input_data_list:
		l = len(i)
		if maxlength<l:
			maxlength = l

	for i in test_input:
		l = len(i)
		if maxlength<l:
			maxlength = l

	for i in test_input:
		l = len(i)
		i+=([0,]*(maxlength-l))

	for i in input_data_list:
		l = len(i)
		i+=([0,]*(maxlength-l))							#----> For all sequences other than the longest, fill zeroes at the end

	input_data_array = np.asarray(input_data_list)		#----> Convert into numpy array

	# 1.3 Convert the output data from integer list to binary list of list

	output_binary_list = []
	for i in output_data_list:							#----> The number 5 is converted to [0, 0, 0, 0, 0, 1, 0, 0, .... , 0] (47 classes)
		temp_list = [0]*47
		temp_list[i] = 1
		output_binary_list.append(temp_list)

	output_data_array = np.asarray(output_binary_list)	#----> List is converted to array

	length = len(input_data_array)
	assert(length == len(output_data_array))
	
	length = len(test_input)
	assert(length == len(test_output))

	dataset = np.reshape(input_data_array, (len(input_data_array), maxlength, 1))
	test = np.reshape(test_input, (len(test_input), maxlength, 1))	
	

	#-------------------------------------------------------------------------------------------------------------------------------------#

	#-----------------------------------------------STEP 2. DESIGN THE RNN----------------------------------------------------------------#

	#-------------------------------------------------------------------------------------------------------------------------------------#

	# 2.1 Configure training data characteristics

	with tf.name_scope("inputs"):
		data = tf.placeholder(tf.float32, [None, maxlength, 1], name="training_x")	
		target = tf.placeholder(tf.float32, [None, 47], name="training_y")	#---> 1 - no. of dimensions, 47 - number of classes

	num_hidden = 300														#----> Number of hidden cells/hidden layers

	# 2.2 Configure the LSTM cell

	cell = tf.nn.rnn_cell.LSTMCell(num_hidden, state_is_tuple=True)			#---> tf.nn.rnn_cell.LSTMCell.__init__(num_units, input_size=None, use_peepholes=False, cell_clip=None, initializer=None, num_proj=None, num_unit_shards=1, num_proj_shards=1, forget_bias=1.0, state_is_tuple=False, activation=tanh)

	# 2.3 Configure the RNN for the LSTM

	val, state = tf.nn.dynamic_rnn(cell, data, dtype=tf.float32)			#---> tf.nn.dynamic_rnn(cell, inputs, sequence_length=None, initial_state=None, dtype=None, parallel_iterations=None, swap_memory=False, time_major=False, scope=None)

	# 2.4 Convert the result to desired form

	val = tf.transpose(val, [1, 0, 2])
	last = tf.gather(val, int(val.get_shape()[0])-1)

	# 2.5 Allocate space for weights and biases

	with tf.name_scope("layers"):	
		weights = tf.Variable(tf.truncated_normal([num_hidden, int(target.get_shape()[1])]), name="weights")	
		#---> truncated_normal is used to generate random numbers with normal distribution, to a vector of size num_hidden * number of classes
	
		biases = tf.Variable(tf.constant(0.1, shape=[target.get_shape()[1]]), name="biases")

	# 2.6 Configure the Prediction function

	prediction = tf.nn.softmax(tf.matmul(last, weights)+biases, name="prediction")	#---> tf.nn.softmax(logits, dim=-1, name=None)

	# 2.7 Calculate cross entropy

	cross_entropy = -tf.reduce_sum(target * tf.log(prediction), name="cross_entropy")	#---> tf.reduce_sum(input_tensor, axis=None, keep_dims=False, name=None, reduction_indices=None) Calculates the sum of the tensor, Adding the log term helps in penalizing the model more if it is terribly wrong and very little when the prediction is close to the target

	# 2.8 Configure the Optimizer

	with tf.name_scope("optimizer"):
		optimizer = tf.train.AdamOptimizer()				#---> tf.train.AdamOptimizer.__init__(learning_rate=0.001, 
		minimize = optimizer.minimize(cross_entropy)		#---> beta1=0.9, beta2=0.999, epsilon=1e-08, use_locking=False, name='Adam')

	# 2.9 Configure the initialize all variables function

	init_op = tf.initialize_all_variables()

	# 2.10 Create the saver to save the weights and biases to disk

	#saver = tf.train.Saver()

	#-------------------------------------------------------------------------------------------------------------------------------------#

	#------------------------------------------------STEP 3. EXECUTION--------------------------------------------------------------------#

	#-------------------------------------------------------------------------------------------------------------------------------------#

	# 3.1 Create a tensor flow session
	sess = tf.Session()

	# 3.2 Create the graph summary writer
	writer = tf.train.SummaryWriter("logs/",sess.graph)

	# 3.3 Run init_op function
	sess.run(init_op)

	# 3.4 Run minimize function, pass the dataset x and y

	print(sess.run(minimize, {data:dataset, target:output_data_array}))

	# 3.5 Save the variables to disk after training
	#save_path = saver.save(sess, "variables.ckpt")
	
	#-------------------------------------------------------------------------------------------------------------------------------------#
	
	#-----------------------------------------------STEP 4. PREDICT-----------------------------------------------------------------------#
	
	#-------------------------------------------------------------------------------------------------------------------------------------#
	
	result=sess.run(prediction, {data: test})
	assert(length == len(result))
	total=0;
	correct=0;
	predicted=[]
	result_file = open("result_file.txt", "w")
	for i in range(0, length):
		result_file.write("Case "+str(i)+":\n")
		json.dump(result[i].tolist(), result_file)
		result_file.write("\n")
		maxi = max(result[i])
		result_file.write("Max probability is: "+str(maxi)+"\n")
		sublength = len(result[i])
		assert(sublength==47)
		temp=[]
		for j in range(0, sublength):
			if(result[i][j]==maxi):
				temp.append(j)
		result_file.write("Classes with max probability: ")
		json.dump(temp, result_file)
		result_file.write("\n")
		predicted.append(temp)

	assert(len(predicted)==length)
	for i in range(0, length):
		if(test_output[i] in predicted[i]):
			correct+=1
		result_file.write(str(predicted[i])+" "+str(test_output[i])+"\n")

	accuracy = float(correct/length) * 100
	result_file.write("\nAccuracy is: "+str(accuracy))
	
	sess.close()
