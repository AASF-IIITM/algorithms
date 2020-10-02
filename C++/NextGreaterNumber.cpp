/* AUTHOR : Sayantan Banerjee (2018IMT-093) 

The problem is to find the Next Greater Number of the given number.
For eg if Input is 5143, then the next Greater is 5314.
If input is 5432, as it is already greatest, print -1.
Input is entered as a string S.

This question is very much common w.r.t to interviews.

*/

#include<bits/stdc++.h>
using namespace std;
int func(char a[],int x,int y)
{
	for(int i=y;i>x;i--)
	{
		if(a[i]>a[x])
		{
			a[i]=a[i]+a[x];
			a[x]=a[i]-a[x];
			a[i]=a[i]-a[x];
			sort(a+x+1,a+y+1);
			return 1;
		}
	}
	return 0;
}

int main()
{
		
	char a[100];
	printf("\nEnter a Number : ");
	scanf("%s",a);
	int n=strlen(a);
	int flag;
	for(int i=n-2;i>=0;i--)
	{
		flag=func(a,i,n-1);
		if(flag==1)
			break;
	}
	cout<<endl;
	if(!flag)
	{
		cout<<-1;
		return 0;
	}
	printf("\nThe Greater Number Is : ");
	for(int i=0;i<n;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}
