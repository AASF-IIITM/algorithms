#include <stdio.h>

void mergeSort(int [], int, int, int);
void partition(int [],int, int);

int main()
{
    int arr[1000];
    int i, size;

    printf("Enter total number of elements:");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for(i = 0; i < size; i++)
    {
         scanf("%d", &arr[i]);
    }
    partition(arr, 0, size - 1);
    printf("After merge sort:\n");
    for(i = 0;i < size; i++)
    {
         printf("%d   ",arr[i]);
    }

   return 0;
}

void partition(int arr[],int low,int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;
        partition(arr, low, mid);
        partition(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }
}

void mergeSort(int arr[],int low,int mid,int high)
{
    int i, mid2, k, low2, temp[50];

    low2 = low;
    i = low;
    mid2 = mid + 1;
    while ((low2 <= mid) && (mid2 <= high))
    {
        if (arr[low2] <= arr[mid2])
        {
            temp[i] = arr[low2];
            low2++;
        }
        else
        {
            temp[i] = arr[mid2];
            mid2++;
        }
        i++;
    }
    if (low2 > mid)
    {
        for (k = mid2; k <= high; k++)
        {
            temp[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (k = low2; k <= mid; k++)
        {
             temp[i] = arr[k];
             i++;
        }
    }

    for (k = low; k <= high; k++)
    {
        arr[k] = temp[k];
    }
}
