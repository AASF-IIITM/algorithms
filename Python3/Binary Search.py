# Input Array
arr = sorted(list(map(int,input().split())))
# Number to search
x = int(input())

def binary_search(left,right,x):
    if left<=right:
        mid = ((right-1)+left)//2

        if arr[mid]==x:
            return True

        # if the arr[mid]<search element
        elif arr[mid]<x:
            return binary_search(left,mid-1,x)
        
        # if arr[mid]>search element
        else:
            return binary_search(mid+1,right,x)
    return False

print(binary_search(0,len(arr)-1,x))
