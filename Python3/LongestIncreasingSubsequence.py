from bisect import insort,bisect_left,bisect_right

def lis(A):
    d = [A[0]]
    n = len(A)
    for i in range(1,n):
        if d[-1] < A[i]:
            d.append(A[i])
        else:
            idx = bisect_left(d, A[i])
            d[idx] = A[i]
        
    return len(d)
    
arr = [1,5,7,4,3]
print(lis(arr))
