#include<stdio.h>
#define INFINITY 2000
#define MAXNODES 4
#define MEMBER 1
#define NONMEMBER 0
void shortpath(int weight[][MAXNODES], int , int ,int * ,int precede[]);
int main(void)
{
	int i,j,s,t;
 	int weight[MAXNODES][MAXNODES],precede[MAXNODES],pd;
  	printf("\n Enter weight matrix ");
  	for(i=0;i<MAXNODES;i++)
   		for(j=0;j<MAXNODES;j++)
     		scanf(" %d",&weight[i][j]);
  	for(i=0;i<MAXNODES;i++)
  	{
    	printf("\n");
    	for(j=0;j<MAXNODES;j++)
     		printf(" %d",weight[i][j]);
  	}
  	printf("\n Enter the starting node and the ending node: ");
  	scanf(" %d %d",&s,&t);
  	shortpath(weight,s,t,&pd,precede);
  	printf("\n The shortest path from node %d to %d is : %d",s,t,pd);
	return(0);
}
void shortpath(int weight[][MAXNODES],int s, int t, int *pd, int precede[])
{
	int distance[MAXNODES],perm[MAXNODES];
 	int current,i,j,k,dc;
 	int smalldist,newdist;
  	for(i=0;i<MAXNODES;i++)
  	{
  		perm[i]=NONMEMBER;
  		distance[i]=INFINITY;
  	}
  	perm[s] = MEMBER;
  	distance[s] = 0;
  	current = s;
  	while(current != t)
  	{
  		smalldist=INFINITY;
  		dc=distance[current];
  		for(i=0;i<MAXNODES;i++)
    	if(perm[i]==NONMEMBER)
    	{
		 	newdist = dc + weight[current][i];
		 	if(newdist < distance[i])
		 	{
				distance[i]=newdist;
				precede[i]=current;
		 	}
		 	if(distance[i] < smalldist)
		 	{
		  		smalldist = distance[i];
		  		k=i;
		 	}
   		}
	   	current = k;
	   	perm[current]=MEMBER;
	}
  	*pd=distance[t];
}
