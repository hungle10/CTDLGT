#include<iostream>
using namespace std;
void quickSort(int A[],int left,int right);
int main()
{
	int A[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	   cin>>A[i];
	quickSort(A,0,n-1);
	for(int i=0;i<n;i++)
	   cout<<A[i]<<" ";
	
	
}
void quickSort(int a[], int l, int r)
{
 int i, j, x;
 if (l >= r) return;
 x = a[(l + r)/2]; //ch?n ph?n t? gi?a làm giá tr? m?c
 i = l; j = r;
 do{
 while(a[i] < x) i++;
 while(a[j] > x) j--;
 if(i <= j) {
 swap(a[i], a[j]);
 i++ ;
 j--;
 }
 } while(i < j) ;
 if(l<j) quickSort(a, l, j);
 if(i<r) quickSort(a, i, r);
}
