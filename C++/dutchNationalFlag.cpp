#include <bits/stdc++.h> 
using namespace std;

#define f(i,x,n) for(int i=x;i<n;i++)
#define ll long long
#define pb(i) push_back(i)
#define mp(i,j) make_pair(i,j)
#define test ll t; cin>>t; while(t--)
  
void dnf(int arr[], int n) 
{ 
    int low = 0; 
    int hi = n-1; 
    int mid = 0; 
  
    //Sort the elements
    while(mid <= hi) 
    { 
        switch (arr[mid]) 
        { 
            case 0: 
                swap(arr[lo++], arr[mid++]); 
                break; 
 
            case 1: 
                mid++; 
                break; 
  
            case 2: 
                swap(arr[mid], arr[hi--]); 
                break; 
        } 
    } 
} 
  
void print(int[] arr, int n) 
{ 
    f(i,0,n)
    {
       cout<<arr[i]<<" ";
    }
} 
  
int main() 
{ 
    int a[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int len = sizeof(a)/sizeof(a[0]);
  
    dnf(a,n); 
  
    cout<<"After sorting: "; 
    print(a,n); 
  
    return 0; 
} 
