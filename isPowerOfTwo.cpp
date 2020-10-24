#include <bits/stdc++.h>
using namespace std;
#define bool int 
bool isPowerOfTwo (int x) 
{ 
    return x && (!(x&(x-1))); 
} 
 
int main() 
{ 
   int n;
   cin>>n;
   if(isPowerOfTwo(n))
   cout<<"YES";
   else 
   cout<<"NO";
    return 0; 
} 
