#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
const int n=100000;
int a[n]={0};
void sieve()
{
    for(int i=2;i*i<=n;i++)
    {
        if(a[i]==0)
        {
            v.push_back(i);
        }
        for(int j=i*i;j<=n;j+=i)
        {
            a[j]=1;
        }
    }
}

int main()
{
     //just create sieve array for first time for primes numbers
    sieve();
    long int m, n;
    //the range of input where 1<=n<=m<=10^9
    //(n0m)<=10^5
    cin>>m>>n;
    // segmented sieve array
    bool segment[n-m+1];
    for(int i=0;i<n-m+1;i++)
    {
        segment[i]=0;
    }




    for(auto i:v)
    {
        if(i*i>n)
        {
            break;//like if we have primes numbers
                //which is greater than the range
                // just break the loop
        }
        int start=(i/m)*i;//just nearest multiple of i
                          // in (m, n) range
        if(i<=n&&i>=m)
        {
            start=i*2;//it can atleast be start from i*2
                    //range is considered okay
        }

        for(int j=start;j<=n;j+=i)
        {
            segment[j-m]=1;//just mark multiple of start
                           // to 1 that means non- primes
        }
    }
    // print the array
    for(int i=m;i<=n;i++)
    {
        if(segment[i-m]==0&&i!=1)
        {
            cout<<i<<" ";
        }
    }




    return 0;
}
