#include<iostream>
using namespace std;
#include<string>
struct NODE{
	string name;
	int diemCTDL;
    NODE* next;
};
struct LINKEDLIST{
	NODE* Head;
	NODE* Tail;
};


void addFirst(LINKEDLIST& myList,NODE* p);
void addNode(LINKEDLIST &myList,NODE* q,NODE* p);
void InitList(LINKEDLIST &myList);
void addLast(LINKEDLIST& myList,NODE* p);
NODE* createNode(string Name,int DiemCTDL);
bool isEmptyList(LINKEDLIST myList);
void xuat(LINKEDLIST myList);
void quickSort(LINKEDLIST& myList);
void removeLast(LINKEDLIST& myList);
void removeNode(LINKEDLIST &myList,NODE* q);
void xoaHocSinh(LINKEDLIST &myList);


int main()
{
	LINKEDLIST myList;
	InitList(myList);
	
    NODE* hs1=createNode("Le Thai Hung",3);
	NODE* hs2=createNode("Do Hoang Giang",10);
	NODE* hs3=createNode("Phung Ngoc Anh Thu",5);
	NODE* hs4=createNode("Le Thai Khang",3);
	NODE* hs5=createNode("Dang Quoc Bao",7);
	
	addFirst(myList,hs1); //checked
	addNode(myList,hs1,hs2);
	addNode(myList,hs2,hs3);
	addNode(myList,hs3,hs4);
    addNode(myList,hs4,hs5);
	
  //  xoaHocSinh(myList);
    
	//xuat(myList);
	
	//cout<<endl;
    cout<<"Xoa hoc sinh co diem CTDL nho hon 5"<<endl;
    xoaHocSinh(myList);
    xuat(myList);
    cout<<endl;
    cout<<"Sap xep danh sach hoc sinh "<<endl;
	quickSort(myList);
    xuat(myList);
   
  
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
NODE* createNode(string Name,int DiemCTDL)
{
	NODE* p=new NODE;
	if(p==NULL)
	return NULL; // khong du bo nho
	p->name=Name;
	p->diemCTDL=DiemCTDL;
	p->next=NULL;
	return p;
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
bool isEmptyList(LINKEDLIST myList)
{
	if(myList.Head==NULL)
	   return true;
	return false;
}
void xuat(LINKEDLIST myList)
{
	
	for(NODE* p=myList.Head;p!=NULL;p=p->next)
	{
	   cout<<p->name<<" "<<p->diemCTDL;
	   cout<<endl;
	}
	
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
		if(q->diemCTDL>pivot->diemCTDL)	
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
void removeLast(LINKEDLIST& myList)
{
	if(isEmptyList(myList)==true)
	   return;
	else
	{
		if(myList.Head==myList.Tail)
		    myList.Head=myList.Tail=NULL;
		else
		{
			NODE*q=myList.Tail;
			for(NODE*p=myList.Head;p!=NULL;p=p->next)
			   if(p->next==myList.Tail)
			      {
			      	p->next=NULL;
			      	myList.Tail=p;
			       }
				delete q;
		}
	}
}
void xoaHocSinh(LINKEDLIST &myList)
{
	NODE* p=myList.Head;
	while(p!=NULL&&p->next!=NULL)    // xet truong hop 8 3 2 9 0 /vong lap chi xet va xoa cac phan tu 3 2 9 
    {                                
    	do
    	{
        NODE*q=p->next;
        int diem=q->diemCTDL;
    	if(diem<5)
         	removeNode(myList,p); //sau khi remove p->next cung duoc cap nhat vi du sau khi xoa 3 p->next se tro thanh 2
        }
        while(p->next->diemCTDL<5);
       p=p->next; // sau khi xoa het 3 2 p se duoc cap nhat tu 8 sang 9 
    }
    
    //kiem tra phan tu dau
    if(myList.Head->diemCTDL<5)
	    {
	    	NODE* tmp=myList.Head;
	    	myList.Head=myList.Head->next;
	    	delete tmp;
	    }
	//kiem tra phan tu cuoi
	if(myList.Tail->diemCTDL<5)
	    {
	    	removeLast(myList);
	     }
}
void removeNode(LINKEDLIST &myList,NODE* q)
{
	NODE*p=q->next;
	if(p==NULL)
	return;
	else
	{
		q->next=p->next;
		if(p==myList.Tail)
		   myList.Tail=q;
		delete p;
	}
}
