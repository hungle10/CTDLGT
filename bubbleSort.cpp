#include<iostream>
using namespace std;
int main()
{
	int A[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	  cin>>A[i];
	for(int j=n-1;j>=0;j--)
	   for(int i=0;i<j;i++)
	      if(A[i]>A[i+1])
	         {
	         	int temp=A[i];
	         	A[i]=A[i+1];
	         	A[i+1]=temp;
	         }
	for(int i=0;i<n;i++)
	   cout<<A[i];
	   
}
