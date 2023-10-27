#include<iostream>
using namespace std;
struct NODE{
	int info;
	NODE*next;
};
struct STACK
{
	NODE*top;
};
void initStack(STACK &myStack);
NODE* CreateNode(int x);
void push(STACK &myStack,NODE*p);
int top(STACK &myStack);
int pop(STACK &myStack);
int main()
{
	STACK myStack;
	initStack(myStack);
	NODE*p=CreateNode(1);
	push(myStack,p);
    cout<<top(myStack)<<endl;
	cout<<pop(myStack);

}
void initStack(STACK &myStack)
{
	myStack.top==NULL;
}
NODE* CreateNode(int x)
{
	NODE*p=new NODE;
	if(p==NULL)
	   return NULL;
	else
	{
	p->info=x;
	p->next=NULL;
	return p;
	}
}
void push(STACK &myStack,NODE*p)
{
	p->next=myStack.top;
	myStack.top=p;
}
int top(STACK &myStack)
{
	return myStack.top->info;
}
int pop(STACK &myStack)
{
	NODE*p=new NODE;
	p=myStack.top;
	int x=p->info;
	myStack.top=myStack.top->next;
	delete p;
	return x;
}
