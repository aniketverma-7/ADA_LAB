#include<bits/stdc++.h>
using namespace std;

void solve(int a[],int n,int target)
{
	int lower = 0;
	int high = n-1;
	int m;
	while(lower<=high)
	{
		m = (lower+high)/2;
		if(a[m]==target)
		{
			cout<<"Found at "<<m+1<<endl;
			return;
		}

		if(a[m]>target)
		{
			high=m-1;
		}
		else
		{
			lower = m+1;
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

	sort(a,a+(sizeof(a)/sizeof(a[0])));
	solve(a,n,target);				
	return 0;
}