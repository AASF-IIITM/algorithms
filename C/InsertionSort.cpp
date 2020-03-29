#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size)
{
    int i,j,key;

    for(i=1;i<size;i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0&&arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }

}

void print(int arr[],int size)
{

    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}


int main()
{
    int arr[] = {12,11,13,5,6};
    int size = sizeof(arr)/sizeof(int);
    sort(arr,size);
    print(arr,size);
    return 0;
}
