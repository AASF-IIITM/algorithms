/*
  Given n non-negative integers representing an elevation map
  where the width of each bar is 1, compute how much water it 
  can trap after raining.
*/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
        
    int n=height.size();
    vector<int>left(n), right(n);
    
    left[0]=height[0],right[n-1]=height[n-1];
    
    for(int i=1;i<n;i++) {
        left[i]=max(left[i-1],height[i]);
    }
    
    for(int i=n-2;i>=0;i--) {
        right[i]=max(right[i+1],height[i]);
    }
    
    int ans=0;
    
    for(int i=0;i<n;i++) {
        ans+=min(left[i],right[i])-height[i];
    }
    
    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<int>height(n);
    for(int i=0;i<n;i++) {
        cin>>height[i];
    }

    int ans=trap(height);
    cout<<ans<<endl;

    return 0;
}