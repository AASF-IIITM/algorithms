#include<bits/stdc++.h>
using namespace std;
void path(int n,int a,int b)
{
int at=0,bt=0;
cout<<"(0,0)\n";
while(at!=n&&bt!=n)
{
if(at==0)
{
at=a;
cout<<"("<<at<<","<<bt<<")\n";
}
else if(bt==b)
{
bt=0;
cout<<"("<<at<<","<<bt<<")\n";
}
else
{
int mini=min(at,b-bt);
at-=mini;
bt+=mini;
cout<<"("<<at<<","<<bt<<")\n";
}
}
}
int main()
{
int a,b,n;
cout<<"Enter capacity of first jug: ";
cin>>a;
cout<<"Enter capacity of second jug: ";
cin>>b;
cout<<"Enter amount of water you want to fill in either of the two jugs: ";
cin>>n;
if((n<a||n<b)&&n%__gcd(a,b)==0)
{
cout<<"\nPath from initial to solution state:\n";
path(n,a,b);
}
else
 cout<<"\nNot possible to fill the given amount of water in either of the two jugs\n";
return 0; }
