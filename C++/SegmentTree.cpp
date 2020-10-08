/* Segment Tree Implementation

   A Segment Tree is a data structure that allows answering range queries over an array effectively, 
   while still being flexible enough to allow modifying the array. 
   This includes finding the sum of consecutive array elements a[l…r], or finding the minimum element in a such a range in O(logn) time.
   Between answering such queries the Segment Tree allows modifying the array by replacing one element,
   or even change the elements of a whole subsegment (e.g. assigning all elements a[l…r] to any value, or adding a value to all element in the subsegment).
   
   However, for range(or subsegement updates), we also need to use lazy propagation technique to make it work in O(logn) time.
   The below code only shows modification at a single position at a time.
     
*/

#include<bits/stdc++.h>
using namespace std;

// Function to merge the ranges according to problem requirements
// Here, we are finding the minimum in a range
int combine(int x, int y)
{
	return min(x,y);
}

// Building the segment tree in O(n)
void buildtree(int ar[], int tree[], int index, int s, int e)
{
	if(s==e)
	{
		tree[index] = ar[s];
		return;
	}
	
	int mid = (s+e)/2;
	buildtree(ar,tree,2*index,s,mid);
	buildtree(ar,tree,2*index+1,mid+1,e);
	
	tree[index] =  combine(tree[2*index],tree[2*index+1]);
}

// Answering queries like minimum element in a range
// works in O(logn)
int queryans(int tree[],int index,int qs,int qe,int s,int e)
{
	if(qe<s or qs>e) return INT_MAX;
	
	if(qs<=s and qe>=e) return tree[index];
	
	int mid = (s+e)/2;
	int left = queryans(tree,2*index,qs,qe,s,mid);
	int right = queryans(tree,2*index+1,qs,qe,mid+1,e);
	
	return combine(left,right);
}

// Updating(or modifying) a single value at a time
// works in O(logn)
void updatenode(int tree[],int index, int pos, int val, int s, int e)
{
	if(pos<s or pos>e) return;
	
	if(s==e)
	{
		tree[index]+=val;
		return;
	}
	
	int mid = (s+e)/2;
	updatenode(tree,2*index,pos,val,s,mid);
	updatenode(tree,2*index+1,pos,val,mid+1,e);
	
	tree[index] =  combine(tree[2*index], tree[2*index+1]);
}

int main()
{
	int n;
	cin>>n;
	
	int ar[n];
	for(int i=0;i<n;i++) cin>>ar[i];
	
	int tree[4*n+1];
	int start = 0, end = n-1;
	
	// Function call to buildtree
	buildtree(ar,tree,1,start,end);
	
	int q;
	cin>>q;
	
	// Queries
	while(q--)
	{
		int type;
		cin>>type;
		
		// Type 0 means to answering query like 'find minimum in ar[l....r]'
		if(type==0)
		{
			int l,r;
			cin>>l>>r;
			
			l--;          // Changing indexes 
			r--;          // to 0-based
			cout<< queryans(tree,1,l,r,start,end) <<endl;
		}
		// Type 1 means to modify a given position in the array
		else if(type==1)
		{
			int pos,val;
			cin>>pos>>val;
			
			pos--;
			updatenode(tree,1,pos,val,start,end);
		}
	}
	return 0;
}
