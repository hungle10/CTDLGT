#include<iostream>
using namespace std;
int main()
{
	int A[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	   cin>>A[i];
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		    if(A[j]<A[min])  //sap xep tang dan
		        {
		        	min=j;
		        }
		if(min!=i)
		{
			int temp=A[i];
			A[i]=A[min];
			A[min]=temp;
		}
	}
	for(int i=0;i<n;i++)
	   cout<<A[i];
}
