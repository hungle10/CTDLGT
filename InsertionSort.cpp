#include<iostream>
using namespace std;
int main()
{
	int A[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	   cin>>A[i];
	
	for(int i=1;i<n;i++)
	{
		int pos=i;
		int x=A[pos];
		while(pos>0&&A[pos-1]>x)
		   {
		   	 A[pos]=A[pos-1];
		   	 pos--;
		   	}
	    A[pos]=x;
	}
	for(int i=0;i<n;i++)
	   cout<<A[i];
}
