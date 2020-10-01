#include<iostream>
using namespace std;

int KnapSack(int tot_wt,int wt[],int val[],int n){
  if(tot_wt==0 ||n==0)
    return 0;
    int x=(tot_wt-wt[n-1]>=0)?val[n-1]+KnapSack(tot_wt-wt[n-1],wt,val,n-1):0;
  return max(x,KnapSack(tot_wt,wt,val,n-1));
  }

int main(){
  int val[] = { 60, 100, 120 };
  int wt[] = { 10, 20, 30 };
  int W = 50;
  int n = 3;
  cout << KnapSack(W, wt, val, n);
  return 0;
  }
