#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int start,int mid,int end)
{
	int f = mid-start+1;
	int s = end - mid;

	int first[f],second[s];

	for(int i=0;i<f;i++)
		first[i]=arr[i+start];

	for(int i=0;i<s;i++)
		second[i]=arr[i+mid+1];

	int index=start,index1=0,index2=0;

	while(index1<f && index2<s)
	{
		if(first[index1]<second[index2])
			arr[index++]=first[index1++];
		
		else
			arr[index++]=second[index2++];
	}

	while(index1<f)
		arr[index++]=first[index1++];

	while(index2<s)
		arr[index++]=second[index2++];
}


void mergeSort(int arr[],int start,int end)
{
	if(start<end)
	{
		int mid = start + (end-start)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);	
	}
}

int main()
{
	int arr[] =  {212, 140, 106, 202, 8, 232, 203, 10, 11, 50};
	int n = 10;
	for(int i:arr)cout<<i<<" ";
	cout<<endl;
	int k=0;
	for(int i:arr)k=max(k,i);

	mergeSort(arr,0,n-1);
	
	cout<<endl;
	for(int i:arr)cout<<i<<" ";
	cout<<endl;	
	return 0;
}