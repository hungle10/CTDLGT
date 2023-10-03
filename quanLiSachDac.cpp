#include<iostream>
#define MAX 100
using namespace std;
struct HOCSINH{
	string name;
	int diemCTDL;
};
struct DANHSACH{
	HOCSINH A[MAX];
	int n;
};

void taoDanhSach(DANHSACH &HS,string name,int diemCTDL);
void xuatDanhSach(DANHSACH HS);
void xoaPhanTuBatKi(DANHSACH &B,int viTri);
void xuLyXoaHocSinh(DANHSACH &B);
int maxDiem(DANHSACH HS);
void xuLyHocSinhDauVaCuoi(DANHSACH &HS);
void addFirst(DANHSACH& HS,HOCSINH x);
int minDiem(DANHSACH HS);
void addLast(DANHSACH& HS,HOCSINH x);

int main()
{
      DANHSACH HS;
      HS.n=0;
      
      taoDanhSach(HS,"Le Thai Hung",9);
      taoDanhSach(HS,"Do Hoang Giang",10);
      taoDanhSach(HS,"Phung Ngoc Anh Thu",3);
      taoDanhSach(HS,"Dang Quoc Bao",4);
      taoDanhSach(HS,"Le Thai Khang",8);
      
      
    
      
      
    xuLyHocSinhDauVaCuoi(HS);
    
     xuatDanhSach(HS);
     cout<<endl;
     
      xuLyXoaHocSinh(HS);
      
    xuatDanhSach(HS);
     
     
    
}
void xuLyHocSinhDauVaCuoi(DANHSACH &HS)
{
	for(int i=0;i<HS.n;i++)
	   if(HS.A[0].diemCTDL!=maxDiem(HS))
	       if(HS.A[i].diemCTDL==maxDiem(HS))
	       {
	       	   HOCSINH temp= HS.A[i];
	           xoaPhanTuBatKi(HS,i);
	           addFirst(HS,temp);
	    }
	for(int i=0;i<HS.n;i++)
	    if(HS.A[HS.n-1].diemCTDL!=minDiem(HS))
	     if(HS.A[i].diemCTDL==minDiem(HS))
	       {
	       	HOCSINH temp=HS.A[i];
	       	xoaPhanTuBatKi(HS,i);
	       	addLast(HS,temp);
		   }
	   
}
void addLast(DANHSACH& HS,HOCSINH x)
{
	HS.n++;
	HS.A[HS.n-1]=x;
}
void addFirst(DANHSACH& HS,HOCSINH x)
{
	HS.n++;
	for(int i=HS.n;i>0;i--)
	   HS.A[i]=HS.A[i-1];
	HS.A[0]=x;
}
int maxDiem(DANHSACH HS)
{
	int max=-10000;
	for(int i=0;i<HS.n;i++)
	   if(HS.A[i].diemCTDL>max)
	      max=HS.A[i].diemCTDL;
	return max;
}
int minDiem(DANHSACH HS)
{
	int min=10000;
	for(int i=0;i<HS.n;i++)
	   if(HS.A[i].diemCTDL<min)
	      min=HS.A[i].diemCTDL;
	return min;
}
void taoDanhSach(DANHSACH &HS,string name,int diemCTDL)
{
	HS.A[HS.n].name=name;
	HS.A[HS.n].diemCTDL=diemCTDL;
    HS.n++;
}
void xuatDanhSach(DANHSACH HS)
{
	for(int i=0;i<HS.n;i++)
	{
	   cout<<HS.A[i].name<<" "<<HS.A[i].diemCTDL;
	cout<<endl;
	}
}
void xuLyXoaHocSinh(DANHSACH &B)
{
	//ham xoa hoc sinh
	int i=0;
	while(i<B.n-1)
	{
	  if(B.A[i].diemCTDL<5)
	       xoaPhanTuBatKi(B,i);
	  else 
	    i++;
	}
	if(B.A[B.n-1].diemCTDL<5)
	    B.n--;
}
void xoaPhanTuBatKi(DANHSACH &B,int viTri)
{
	for(int i=viTri;i<B.n-1;i++)
	    B.A[i]=B.A[i+1];
	B.n--;
}



