#include <bits/stdc++.h> 
using namespace std; 

void selectionSort(int arr[],int n)
{
  for(int i=0;i<n-1;i++) // checking each and every element as boundary element
  {
  	for(int j=i+1;j<n;j++) //traversing the sub-array for any smaller element
  	{
  		if(arr[j]<arr[i]) //swapping the elemnts if the subarray element is smaller than boundary element
  		{
  			int temp = arr[i];
  			arr[i] = arr[j];
  			arr [j] = temp;
		}
	}
  }
  cout << "\nThe sorted array is-\n"; //printing the sorted array
  	for(int i=0;i<n;i++)
	{
		cout << arr[i] << "\n";
	}	
}

int main()
{
	int n;
	cout << "Enter the no. of Elements-\n";
	cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) //Entering elements in the array
	{
		cout << "Enter the elements-\n";
		cin >> arr[i];
	}
	selectionSort(arr,n);
	
}
