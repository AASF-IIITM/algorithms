/* 
The problem is to find the element in the
array that has more than N/2 occurances 
*/

#include<bits/stdc++.h>
using namespace std;

//Function for finding the majority element

int mooreVoting(vector<int>& arr) {

    int votes=0, candidate=-1, n=arr.size();
    for(int i=0;i<n;i++) {
        if(votes == 0) {
            candidate=arr[i];
        } 
        
        if(candidate == arr[i]) {
            votes++;
        }else {
            votes--;
        }
    }

    int count=0;
    for(int i=0;i<n;i++) {
        if(arr[i] == candidate) count++;
    }

    if(count<=(n/2)) return -1;

    return candidate;
}


int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int majority=mooreVoting(arr);

    cout<<"The element with more than N/2 occurance is "<<majority<<endl;

    return 0;
}