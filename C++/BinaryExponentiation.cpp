#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;

ll Power(ll x, ll y) {
	ll res = 1;
	while(y > 0) {
		if(y & 1) 
			res = (res * x);
		y >>= 1;
		x = (x * x);
	}
	return res;
}

ll PowerMod(ll x, ll y, ll p) {
	ll res = 1;
	x = x % p;
	while(y > 0) {
		if(y & 1) 
			res = (res * x) % p;
		y >>= 1;
		x = (x * x) % p; 
	}
	return res;
}

int main() {
  cout << Power(2, 10) << endl;
	cout << PowerMod(2, 10, mod);
  return 0;
}
