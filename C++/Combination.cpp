#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll computeNcR(int n, int r) {
    ll p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
	
	/*
		Alternate Method but tends to overflow.
		
		r = min(r, n - r);
		ll res = 1;
		for(int i = 0; i < r; i++) {
			res *= (n - i);
			res /= (i+ 1);
		}
		return res;
	*/
	
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--; 
            r--; 
        }
    } else
        p = 1;

    return p;
}

int main() {
  cout << computeNcR(5, 2);
}
