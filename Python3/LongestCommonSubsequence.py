"""
Longest Common Subsequence Problem solution using DP.
Given two sequences, find the length of longest subsequence present in both of them.
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 

"""

X="abcdgh"
Y="abedfhr"


def LCSDP(X,Y,n,m):
    #creating dp array of dimensions 'n x m'
    dp=[[-1 for j in range(m+1)]for i in range(n+1)]

    #Initializing 1st column to 0
    for i in range(n+1):
        dp[i][0]=0
    
    #Initializing 1st row to 0
    for j in range(1,m+1):
        dp[0][j]=0
    
    #Starting loop for 2nd row and 2nd column 
    for i in range(1,n+1):
        for j in range(1,m+1):
            #If both characters are same
            if X[i-1]==Y[j-1]:
                dp[i][j]= 1+dp[i-1][j-1]
            #if both characters are not same
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    return dp[n][m]

print("The length of longest common subsequence is: ",LCSDP(X,Y,len(X),len(Y)))