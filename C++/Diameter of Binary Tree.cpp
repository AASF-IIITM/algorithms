#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
//function to create tree
node* createTree(int *v)
{
    static int i=0;
    int value=v[i];
    i++;
    //if value is -1 then that node will be NULL
    if(value==-1)
    {
        return NULL;
    }
    //IF  value is not -1 then create a new node
    node *root=new node(value);
    //this will call left tree of node
    root->left=createTree(v);
    //this will call right tree of node
    root->right=createTree(v);
    return root;

}

//function to return diameter of binary tree in O(n)
//approach would be bottom up like poster order
pair<int, int> diameter(node *root)
{
    pair<int, int>p;
    if(root==NULL)
    {
        p.first=0;
        p.second=0;
        return p;
    }
    // we have to just call from leaf node and return height
    //diameter to parent node
    pair<int, int> lheight=diameter(root->left);
    pair<int, int >rheight=diameter(root->right);

    pair<int, int >p1;

    //p1.first would be height of tree to parent node
    // from leaf node

    p1.first=max(lheight.first, rheight.first)+1;

    // p2.second calculates diameter of tree
    //which can be calculated height of
    // left subtree and right subtree

    p1.second=lheight.first+rheight.first;

    // at last return the pair of diameter
    // of binary tree to the parent node

    return p1;
}

int main()
{
    //input array
    int v[]={8, 10, 1, -1, -1, 6, 9, -1, -1, 7, -1, -1, 3, -1, 14, 13, -1, -1, -1};
    node *root;
    // build tree
    root=createTree(v);
    // diameter function will calculate diameter of the tree
    pair<int, int>p=diameter(root);
    // print the diameter of binary tree
    cout<<"Diameter of Binary Tree: "<<p.second<<endl;
   return 0;
}
