#include<iostream>
using namespace std;
struct NODE{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
NODE* timKiem(NODE* tree,int x);
void themNode(NODE* &tree,int x);
void RootLR(NODE* tree);
void khoiTao(NODE* &tree);
int maxTree(NODE* tree);
int minTree(NODE* tree);
void diTimNodeTheMang(NODE* &X,NODE* &Y);
void xoaNode(NODE* &tree,int x);//xóa node b?t kì

int main()
{
	NODE* tree=new NODE;
	khoiTao(tree);
	themNode(tree,7);
	themNode(tree,6);
	themNode(tree,1);
	themNode(tree,3);
	RootLR(tree);
	cout<<endl;
	xoaNode(tree,3);
	RootLR(tree);
}
void khoiTao(NODE* &tree)
{
     tree=NULL;
}
NODE* timKiem(NODE* tree,int x)
{
	if(tree==NULL)
	    return NULL;
	else
	{
		if(x<tree->data)
		   timKiem(tree->pLeft,x);
		else if(x>tree->data)
		   timKiem(tree->pRight,x);
		else
		  return tree;
	}
}
void themNode(NODE* &tree,int x)
{
	if(tree==NULL)
	   {
	   	 NODE* p=new NODE;
	   	 p->data=x;
	   	 p->pLeft=NULL;
	   	 p->pRight=NULL;
	   	 tree=p;
	   	}
	else
	  {
	  	if(x<tree->data)
	  	    themNode(tree->pLeft,x);
	  	else if(x>tree->data)
	  	    themNode(tree->pRight,x);
	  }
}
void RootLR(NODE* tree)
{
	if(tree!=NULL)
	{
		cout<<tree->data;
		RootLR(tree->pLeft);
		RootLR(tree->pRight);
	}
}
void xoaLa(NODE* &tree,int x)
{
	if(tree==NULL)
	    return;
	if(x<tree->data)
	xoaLa(tree->pLeft,x);
	else if(x>tree->data)
	xoaLa(tree->pRight,x);
    else
      {
      	delete tree;
      }
}
int maxTree(NODE* tree)
{
	if(tree->pRight==NULL)
	    return tree->data;
	return maxTree(tree->pRight);
}
int minTree(NODE* tree)
{
	if(tree->pLeft==NULL)
	    return tree->data;
	return maxTree(tree->pLeft);
}
void xoaNode(NODE* &tree,int x)//xóa node b?t kì
{
	if(tree==NULL)
	   return;
	else
	{
		if(tree->data<x)
		    xoaNode(tree->pRight,x);
		else if(tree->data>x)
		    xoaNode(tree->pLeft,x);
		else //data=x 
		{
			NODE* X=tree; //node the mang
			if(tree->pLeft==NULL)
			   {
			   	 tree=tree->pRight;  
			   	}
			else if(tree->pRight==NULL)
			   {
			   	 tree=tree->pLeft;
			   	}
			else //node can xoa la node co hai con
			{
				// C1 NODE the mang la NODE nho nhat ben phai = trai nhat ben phai
				NODE*Y=tree->pRight; //node Y la node the mang cho node can xoa
				//C2 NODE the mang la NODE lon nhat ben trai=phai nhat ben trai
				//NODE*Y=tree->pLeft;
				diTimNodeTheMang(X,Y);
			}	
			delete X;
		}
	}
}
//ham tim node the mang
void diTimNodeTheMang(NODE* &X,NODE* &Y)
{
	if(Y->pLeft!=NULL)
	   diTimNodeTheMang(X,Y->pLeft); //tim node trai nhat
	else
	  {
	  	X->data=Y->data;
	  	X=Y; //cho node X tro den NODE the mang
	  	Y=Y->pRight;//cap nhat lai moi lien ket cua node cha cua node the mang(node ma ta xoa)
	  	//Y->pRight=NULL;
	   }
	/* C2	
	if(Y->pRight!=NULL)
	   diTimNodeTheMang(X,Y->pRight);
	else
	   {
	      X->data=Y->data;
	      X=Y;
	      Y=Y->pLeft;
	    }
       */
}
	  	
	  	
	  	
	   

	
		    

