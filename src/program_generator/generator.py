
def write2file(filename,content):
	file = open(filename,"w")
	file.write(content)
	file.close()

def generate1():
	start 	= "#include<stdio.h> \nint main(){ \nint a,b,c,d,sum,sum2,avg,ans;\na=10;\nb=5;\n"
	end 	= "printf(\"%d\",ans);\n}\n"

	first_part	= [ "c=a+b;\nd=a-b;\n" , "c=a-b;\nd=a+b;\n" ,"c=b+a;\nd=a-b;\n"]

	second_part	= [ "sum=c+d;\navg = sum/2;\n", "sum=d+c;\navg = sum/2;\n" , "avg = (c+d)/2;\n" , "avg = (d+c)/2;\n"  ]

	third_part = [  "sum2=c+d;\nans=sum2/avg;\n" , "sum2=d+c;\nans=sum2/avg;\n" ,"ans=(c+d)/avg;\n" , "ans=(d+c)/avg;\n" ]

	count  = 0

	for i in first_part:
		for j in second_part:
			for k in third_part:
				count+=1
				content =  start+i+j+k+end
				write2file( "programs/"+str(count)+".c",content)

if __name__ == '__main__':
		generate1()