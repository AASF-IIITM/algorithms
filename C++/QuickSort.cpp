#include <bits/stdc++.h> 
using namespace std; 

void printArray(int arr[], int n)
{
	for(int i =0 ;i<n; i++)
	{
		cout << "\n" << arr[i];
	}
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  
 
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] < pivot) //Swapping the elements and changing the lower index
        {
            i++; 
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
		}
    }
    int temp;
    temp = arr[i+1];
    arr[i+1] = arr [high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[],int low,int high)
{
 if(low<high)
 {
 	int pi = partition(arr, low, high);  
 	quickSort(arr,low,pi-1);
 	quickSort(arr,pi+1,high);
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
	quickSort(arr,0,n-1);
	printArray(arr, n); 
	
}
