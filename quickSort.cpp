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
void quickSort(int A[], int left, int right)
{
	int i=left;
	int j=right;
	int pivot=A[(left+right)/2];
	while(i<=j)
	{
		while(A[i]<pivot)
		   i++;
		while(A[j]>pivot)
		  j--;
		if(i<=j)
		{
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i++;
			j--;
		}
	}
	if(left<j)
    quickSort(A,left,j);
    if(i<right)
    quickSort(A,i,right);
}
