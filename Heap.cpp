#include <iostream>

using namespace std;


void heapify(int arr[],int n,int p)
{
	int temp=p;
	int left = p*2+1;
	int right = p*2+2;
	if(left<n and arr[left]>arr[temp])temp=left;
	if(right<n and arr[right]>arr[temp])temp=right;

	if(temp!=p)
	{
		swap(arr[temp],arr[p]);
		heapify(arr,temp,n);
	}
}

void heapSort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);


	// for(int i=0;i<n;i++)cout<<arr[i]<<endl;
	for(int i=n-1;i>0;i--)
	{
		swap(arr[i],arr[0]);
		heapify(arr,i,0);
	}


	
}
int main()
{
	int arr[] = { 661, 621, 591, 621, 391, 391, 931, 981, 601, 61 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	for(int i:arr)cout<<i<<" ";
		cout<<endl;
}
