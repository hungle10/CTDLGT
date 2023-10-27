#include<iostream>
#define M 7
using namespace std;
struct NODE{
	int value;
	NODE* next;
};
void initHash(NODE* heads[]);
NODE* createNode(int x);
int hashFunction(int x) ;
void insertNode(NODE* heads[],int x);
void duyet(NODE* heads[]);
void insertValue(NODE* A[],int x);
void deleteNode(NODE* heads[],int x);
void deleteHashTable(NODE* heads[]);

int main()
{
	NODE* heads[M];
	initHash(heads);
	insertNode(heads,8);
	insertNode(heads,4);
	insertNode(heads,9);
	insertNode(heads,15);
	insertNode(heads,18);
	insertNode(heads,26);

//    insertValue(heads,1);
//    insertValue(heads,8);
//    insertValue(heads,12);
//    insertValue(heads,9);
//    insertValue(heads,3);
//    insertValue(heads,5);
//    insertValue(heads,6);
 
    deleteHashTable(heads);
   // deleteNode(heads,15);

	
	
}
void initHash(NODE* heads[])
{
	for(int i=0;i<M;i++)
	   heads[i]=NULL;
}
NODE* createNode(int x)
{
	NODE* p=new NODE;
	if(p==NULL)
	   return NULL;
	else
	{
		p->value=x;
		p->next=NULL;
		return p;
	}
}
int hashFunction(int x) // ham bam 
{
	return x%M;
}
void insertNode(NODE* heads[],int x)
{
	int key=hashFunction(x);
	NODE* r=heads[key];
	NODE* prev=NULL;
	while(r!=NULL&&r->value<x)
	 {
	 	prev=r;
	 	r=r->next;
	}
	NODE* p=createNode(x);
	if(prev==NULL) // them vao dau
	{
	  heads[key]=p;
	  p->next=r;
	}
	else if(r==NULL)// them vao cuoi
	{
		prev->next=p;
	}
	else
	{
		p->next=r;
		prev->next=p;
	}
}
void duyet(NODE* heads[])
{
	for(int i=0;i<M;i++)
	   if(heads[i]!=NULL)
	      {
	      	cout<<"Bucket"<<i<<" : ";
	      	NODE* p=heads[i];
	      	while(p!=NULL)
	      	{
	      	   cout<<p->value<<" ";
	      	   p=p->next;
	        }
	        cout<<endl;
	      }
}
NODE* search(NODE* heads[],int x)
{
	int key =hashFunction(x);
	NODE* r=heads[key];
	while(r!=NULL&&r->value!=x)
       r=r->next;
    return r;
}
void deleteNode(NODE* heads[],int x) //ham xoa gia tri bang bam
{
	int key=hashFunction(x);
	if(heads[key]->value==x)
	{
		NODE*p=heads[key];
		NODE*q=p;
	    heads[key]=p->next;
	    p=NULL;
	    delete q;
	}
	else
	{
		for(NODE*p=heads[key];p!=NULL;p=p->next)
		    if(p->next->value==x)
		       {
		       	 NODE*q=p->next;
		       	 p->next=q->next;
		       	 p=NULL;
		       	 delete q;
		       	}
	}
}
void deleteHashTable(NODE* heads[]) // ham xoa bang bam 
{
	for(int i=0;i<M;i++)
	 {
	 	for(NODE*p=heads[i];p!=NULL;p=p->next)
	 	    {
	 	    	NODE*q=p;
	 	    	delete q;
	 	    }
	 	heads[i]=NULL;
	}
	cout<<"Da xoa";
}

	
	
	
		
    
