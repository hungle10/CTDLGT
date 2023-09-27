#include<iostream>
using namespace std;
struct NODE{
	int info;
	NODE *next;
};
struct LINKEDLIST{
	NODE* Head;
	NODE* Tail;
};
void xuatNode(LINKEDLIST myList);
void addNode(LINKEDLIST &myList,NODE* q,NODE* p);
void InitList(LINKEDLIST &myList);
NODE* createNode(int x);
bool isEmptyList(LINKEDLIST& myList); 
void addFirst(LINKEDLIST& myList,NODE* p);
void addLast(LINKEDLIST& myList,NODE* p);
void quickSort(LINKEDLIST& myList);
void removeLast(LINKEDLIST& myList);

int main()
{

	LINKEDLIST myList;
	InitList(myList);

	NODE* NODE1=createNode(9);
	NODE* NODE2=createNode(17);
	NODE* NODE3=createNode(2);
	NODE* NODE4=createNode(1);
	NODE* NODE5=createNode(11);
	NODE* NODE6=createNode(8);
 
    addFirst(myList,NODE1);
    addNode(myList,NODE1,NODE2);
    addNode(myList,NODE2,NODE3);
    addNode(myList,NODE3,NODE4);
    addNode(myList,NODE5,NODE6);
    
    //chua sap xep
	xuatNode(myList);
	quickSort(myList);
	cout<<endl;
	xuatNode(myList);
    removeLast(myList);
    xuatNode(myList);
}
void addFirst(LINKEDLIST& myList,NODE* p)
{
	if(isEmptyList(myList)==true)
	   myList.Head=myList.Tail=p;
	else
	{
		p->next=myList.Head;
		myList.Head=p;
	}
	  
}
void addLast(LINKEDLIST& myList,NODE* p)
{
	if(isEmptyList(myList)==true)
	   myList.Head=myList.Tail=p;
	else
	{
		myList.Tail->next=p;
		myList.Tail=p;
	}
}
bool isEmptyList(LINKEDLIST& myList)
{
	if(myList.Head==NULL)
	return true;
	return false;
}
void xuatNode(LINKEDLIST myList)
{
	for(NODE* p=myList.Head;p!=NULL;p=p->next)
	    cout<<p->info;
}
void addNode(LINKEDLIST &myList,NODE* q,NODE* p)//add sau phan tu q
{
	p->next=q->next;
	q->next=p;
	if(myList.Tail==q)
	   myList.Tail=p;
}
void InitList(LINKEDLIST &myList)
{
	myList.Head=myList.Tail=NULL; 
}
NODE* createNode(int x)
{
	NODE* p=new NODE;
	if(p==NULL)
	{
	  cout<<"Khong du bo nho";
	  return NULL;
    }
    p->info=x;
    p->next=NULL;
    return p;
}
void quickSort(LINKEDLIST& myList)
{
	LINKEDLIST myList1;
	LINKEDLIST myList2;
	NODE *pivot,*p;
	InitList(myList1);
	InitList(myList2);
	/*Truong hop danh sach rong hoac co mot phan tu*/
	if(myList.Head==myList.Tail)
	    return;
	/*Phan hoach danh sach thanh 2 danh sach con*/
	pivot=myList.Head;
	p=myList.Head->next;
	while(p!=NULL)
	{
		NODE* q=p;
		p=p->next;
		q->next=NULL;
		if(q->info<pivot->info)	
		  addLast(myList1,q);//them vao danh sach 1
		else
		  addLast(myList2,q);//them vao danh sach 2
	};
	//goi de quy sap xep
	quickSort(myList1);
	quickSort(myList2);
	//ghep noi danh sach 1 + pivot
	if(isEmptyList(myList1)==false)
	{
		myList.Head=myList1.Head;
		myList1.Tail->next=pivot;
	}
	else
	  myList.Head=pivot;
	//ghep noi pivot + danh sach 2
	pivot->next=myList2.Head;
    if(isEmptyList(myList2)==false)
	{
	  myList.Tail=myList2.Tail;
	}
	else
	myList.Tail=pivot;
}
void removeFirst(LINKEDLIST& myList)
{
	if(isEmptyList(myList)==true)
	    return;
	else
	{
		NODE*p=myList.Head;
		if(myList.Head==myList.Tail)
		    myList.Head=myList.Tail=NULL;
		else
		    myList.Head=myList.Head->next;
	    delete p;
	}
}
void removeLast(LINKEDLIST& myList)
{
	if(isEmptyList(myList)==true)
	   return;
	else
	{
		NODE*q=myList.Tail;
		if(myList.Head==myList.Tail)
		    myList.Head=myList.Tail=NULL;
		else
		{
			NODE*p;
			for(p=myList.Head;p!=NULL;p=p->next)
			   if(p->next=myList.Tail)
			      {
			      	delete q;
			      	p->next=NULL;
			      	myList.Tail=p;
			      	return;
			       }
		}
	}
}
			
			
	     
	   

