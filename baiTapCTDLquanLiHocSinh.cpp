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
void quickSort(DANHSACH &HS,int left,int right);
void xoaPhanTuBatKi(DANHSACH &B,int viTri);
void xuLyXoaHocSinh(DANHSACH &B);

int main()
{
      DANHSACH HS;
      HS.n=0;
      
      taoDanhSach(HS,"Le Thai Hung",9);
      taoDanhSach(HS,"Do Hoang Giang",10);
      taoDanhSach(HS,"Phung Ngoc Anh Thu",3);
      taoDanhSach(HS,"Dang Quoc Bao",4);
      taoDanhSach(HS,"Le Thai Khang",8);
      
      quickSort(HS,0,HS.n-1);
      
      xuLyXoaHocSinh(HS);
      
      xuatDanhSach(HS);
      
      
      
    
    
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
void quickSort(DANHSACH &HS,int left,int right)
{
	int i=left,j=right;
	int pivot=HS.A[(left+right)/2].diemCTDL;
	while(i<=j)
	{
		while(HS.A[i].diemCTDL>pivot)
		  i++;
		while(HS.A[j].diemCTDL<pivot)
		  j--;
		if(i<=j)
		{
		   HOCSINH temp=HS.A[i];
			HS.A[i]=HS.A[j];
			HS.A[j]=temp;
			i++;
			j--;
		}
	};
	if(left<j)
	   quickSort(HS,left,j);
	if(i<right)
	   quickSort(HS,i,right);
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



