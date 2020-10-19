#include<iostream>
using namespace std;

int KnapSack(int tot_wt,int wt[],int val[],int n){
  if(tot_wt==0 ||n==0)
    return 0;
    int x=(tot_wt-wt[n-1]>=0)?val[n-1]+KnapSack(tot_wt-wt[n-1],wt,val,n-1):0;
  return max(x,KnapSack(tot_wt,wt,val,n-1));
  }

int KnapSackDP(int tot_wt,int wt[],int val[],int n)
{
    int C[n+1][tot_wt + 1] = {0};
    
    for(int i=0;i<=n; i++)
    {
        for(int w=0;w<=tot_wt; w++)
        {
            if(i==0 || w==0)
            {
                C[i][w] = 0;
            }
            else if(wt[i-1]<=w)
            {
                
                C[i][w] = max(val[i-1] + C[i-1][w - wt[i-1]], C[i-1][w]);
            }
            else
            {
                C[i][w] = C[i-1][w];
            }
        }
    }
    return C[n][tot_wt];
}

int main(){
  int val[] = { 60, 100, 120 };
  int wt[] = { 10, 20, 30 };
  int W = 50;
  int n = 3;
  cout << KnapSackDP(W, wt, val, n);
  return 0;
  }
