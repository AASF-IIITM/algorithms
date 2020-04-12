// C++ program to implement Quick sort with "first element" as pivot
// An O(nlog(n)) algorithm to sort an array
#include<bits/stdc++.h>
using namespace std;
int partition(int A[],int lb,int ub); 

int* quicksort(int A[] , int lb , int ub) // recursive function for performing quick sort
{
	int loc,i;
	if(lb<ub)
	{
		loc=partition(A,lb,ub); // here we get the pivot element from partition function
		// breaking up the array in parts using recursion
		quicksort(A,lb,loc-1);
		quicksort(A,loc+1,ub);
	}
	return A;

}
int partition(int A[],int lb,int ub)  // partition function for arranging the elements in ascending order
{
	int pivot=A[lb]; // selection of pivot element
	int start=lb;
	int end=ub;
	while(start<end)
	{
		while(A[start]<=pivot)
		start++;
		while(A[end]>pivot)
		end--;
		if(start<end)
		{
			swap(A[start],A[end]);	
		}
	}
	swap(A[lb],A[end]);
	return end;	// returing the partition or pivot element to quicksort function
}
// Driver function
int main()
{
    int n,i,lb=0,*arr;
    cout<<"enter no of array elements";
    cin>>n;
    int A[n];
    int ub=n-1;
    cout<<"enter the array elements";
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    arr=quicksort(A,lb,ub);
    cout<<"sorted array is"<<endl;
    for(i=0;i<n;i++)
    {
    	cout<<arr[i]<<" ";
	}   
}
