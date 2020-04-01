//C++ Program to implement Bubble Sort
#include <bits/stdc++.h> 
using namespace std; 

//Function to perform bubble sort
//An O(n^2) algorithm to sort an array
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
    {
        if (arr[j] > arr[j+1])  
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    return;
}  

//Driver Code
int main()
{
    int n; //Size of array
    cout << "Enter the size of the array followed by the array elements: " << endl;
    cin >> n;
    int arr[n] = {0}; //Initializing array with all elements 0
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout << "Sorted Array is: " << endl;
    for(int i = 0 ; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    //Buffer flush
    cout << endl;
    return 0;
}
