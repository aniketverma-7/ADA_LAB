#include<bits/stdc++.h>
using namespace std;

void solve(int a[],int n,int target)
{
	for(int i=0;i<n;i++)
	{
		if(target == a[i])
		{
			cout<<"Found at "<<i<<endl;
			return;
		}
	}

	cout<<"Not Found"<<endl;
}

int main()
{
	int n;
	cout<<"Array Size : ";
	cin>>n;
	int a[n];

	cout<<"Enter Elements : \n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int target;
	cout<<"Targer Value : ";
	cin>>target;

	solve(a,n,target);		

	return 0;
}