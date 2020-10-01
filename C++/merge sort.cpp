#include<iostream>
using namespace std;
void merge(int arr[],int p,int r,int q)
{
    int n1=r-p+1;
    int n2=q-r;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
        a[i]=arr[p+i];
    for(int i=0;i<n2;i++)
        b[i]=arr[r+1+i];
        int i=0,j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i]; k++;i++;
        }
        else
        {
            arr[k]=b[j];k++;j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];k++;i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];k++;j++;
    }
}
void merge_sort(int arr[],int p,int q)
 { int r=p+(q-p)/2;
     if(p<q)
     {
         merge_sort(arr,p,r);
         merge_sort(arr,r+1,q);
         merge(arr,p,r,q);
     }
}
int main()
{   cout<<"Enter total no. of elements in array:";
    int a;
    cin>>a;
    int arr[a];
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,a-1);
    for(int i=0;i<a;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
