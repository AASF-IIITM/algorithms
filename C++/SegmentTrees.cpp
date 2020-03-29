#include<bits/stdc++.h>
using namespace std;
int sizeoftree(int sizeofrealarray)
{
    int temp=0;
    int i=0;
    while(temp<sizeofrealarray)
    {
        temp=pow(2,i);
        i++;
    }
    return 2*temp-1;
}
void createUtil(int segtree[],int node,int start,int end,int array[])
{
    if(start==end)
    {
        segtree[node]=array[start];
    } 
    else{  
    int mid = (start+end)/2;
    //exploring the left child
    createUtil(segtree,2*node,start,mid,array);
    createUtil(segtree,2*node+1,mid+1,end,array);
    segtree[node]=segtree[2*node]+segtree[2*node+1];
    }
}
int getsumutil(int node ,int start ,int end,int l,int r,int segtree[])
{
    //if the given range is outside the range of the node
    if(start>r||end<l)
    {
        return 0;
    }
    //if the range is fully covered by the given interval
    if(l<=start&&r>=end)
    {
        return segtree[node];
    }
    int mid=(start+end)/2;
    //getting the left child sum
    int temp1=getsumutil(2*node,start,mid,l,r,segtree);
    //getting the right child sum
    int temp2=getsumutil(2*node+1,mid+1,end,l,r,segtree);
    return temp1+temp2;
}
int * createtsegmenttree(int arr[],int sizeofrealarray)
{
    int s=sizeoftree(sizeofrealarray);
    int *segtree = new int[s];
    createUtil(segtree,1,0,sizeofrealarray-1,arr);
    return segtree;
}
int getsum(int segtree[],int l,int r)
{
    return getsumutil(1,0,5,l,r,segtree);
}
int main(){
    int n=6;
    int arr[]={1,3,5,7,9,11};
    int *tree=createtsegmenttree(arr,n);
    // for(int i=0;i<14;i++)
    //     cout<<i<<"->"<<tree[i]<<endl;
    
}