#include <bits/stdc++.h>
using namespace std;
/*The far away items (separated by 'gap') are exchanged first and then the gap is reduced until it becomes 1
Time Complexity O(n^2)*/
void shellSort(int arr[], int n)
{
	for(int gap=n/2;gap>0;gap/=2)//starting with a huge gap and then reducing it in further iterations
	{
		for(int i=gap;i<n;i++)
		{
			int j;
			int temp = arr[i];
			for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
			{
				arr[j] = arr[j-gap];
			}
			arr[j] = temp;
		}
	}
}
void printArray(int arr[], int n)
{
	for(int i =0 ;i<n;i++)
	{
		cout << arr[i] << "\n";
	}
}

int main()
{
	int n;
	cout << "Enter The no. of elements-\n";
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cout << "Enter the data-\n";
		cin >> arr[i];
	}
	cout << "Unsorted Array is-\n";
	printArray(arr,n);
	shellSort(arr,n);
	cout << "Sorted Array is-\n";
	printArray(arr,n);
	return 0;
}
