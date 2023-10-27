#include<iostream>
#define MAX 6
using namespace std;

struct QUEUE{
	int A[MAX];
	int nFront;
	int nRear;
};
void initQueue(QUEUE &myQueue);
void enQueue(QUEUE &myQueue,int x);
int main()
{
	QUEUE myQueue;
	initQueue(myQueue);
	enQueue(myQueue,1);
	cout<<myQueue.nFront+1;
   //// cout<<myQueue.A[myQueue.nRear];
//	for(int i=myQueue.nFront;i<=myQueue.nRear;i++)
//	   cout<<i<<" ";
	
}
void initQueue(QUEUE &myQueue)
{
	myQueue.nFront-1;
	myQueue.nRear=-1;
}
void enQueue(QUEUE &myQueue,int x)
{
	 if(myQueue.nFront==-1&&myQueue.nRear==-1)
	              myQueue.nFront=0;

    	if(myQueue.nRear==MAX-1)
	   	    {
	   	    	for(int i=0;i<=myQueue.nRear-myQueue.nFront;i++)
	   	    	    myQueue.A[i]=myQueue.A[i+myQueue.nFront];
	   	    	myQueue.nRear=myQueue.nRear-myQueue.nFront;
	   	    	myQueue.nFront=0;
	   	    }
	
	if((myQueue.nRear-myQueue.nFront)+1==MAX)
	    return;
	else
	{  
	    myQueue.nRear++;
	    myQueue.A[myQueue.nRear]=x;
	}
}
int Front(QUEUE &myQueue)
{

	 	return myQueue.A[myQueue.nFront];
}
int deQueue(QUEUE &myQueue)
{
	    int x=myQueue.A[myQueue.nFront];
	  	myQueue.nFront++;
	  	if(myQueue.nFront>myQueue.nRear)
	  	    initQueue(myQueue);
	  	return x;
	 
}
	
