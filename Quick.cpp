#include<bits/stdc++.h>
using namespace std;


int partition(int a[],int start,int end)
{
	int pivot = a[end];
	int index = start;
	int temp=0;

	for(int i=start;i<end;i++)
		if(a[i]<=pivot)
		swap(a[i],a[index++]);

	swap(a[index],a[end]);
	return index;
}

void quickSort(int a[],int start,int end)
{
	if(start<end)
	{
		int pIndex = partition(a,start,end);
		quickSort(a,start,pIndex-1);
		quickSort(a,pIndex+1,end);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		 in
	}
	quickSort(a,0,n-1);
	cout<<"After Quick Sort : "<<endl;
	for(int x:a)
	{
		cout<<x<<endl;
	}
	cout<<endl;
	return 0;
}