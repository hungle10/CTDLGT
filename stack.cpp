#include<iostream>
#define MAX 100
using namespace std;
struct STACK{
	int A[MAX];
	int top;
};
void push(STACK &myStack,int x);
void initStack(STACK &myStack);
int main()
{
	STACK myStack;
	initStack(myStack);
	push(myStack,1);
    cout<<myStack.A[0];
}
void initStack(STACK &myStack)
{
	myStack.top=-1;
}
void push(STACK &myStack,int x)
{
	if(myStack.top==MAX-1)
	   return;
	else
	{
	 	myStack.A[myStack.top+1]=x;
	 	myStack.top++;
	}
}
int top(STACK myStack)
{
	if(myStack.top==-1)
	   return NULL;
	else
	   return myStack.A[myStack.top];
}
int pop(STACK &myStack)
{
	if(myStack.top==-1)
	   return NULL;
	else
	   {
	   	 int tmp=myStack.A[myStack.top];
	   	 myStack.top--;
	   	 return tmp;
	   	}
}
	
