/*
Program to print all primes less than equal to n using Sieve of Eratosthenes.
Sieve is usied when n is larger
Basic idea is:-
Begin
   Read integer n
   Declare boolean array A of size[n+1] with all its ement equal to 1
   FOR i=2 to i*i<=n
   		if(A[i])
   			FOR j=i*i to j<=n
   				A[j]=0
End
Time Complexity: O(nlog(logn))
*/
#include <bits/stdc++.h>
using namespace std;
void sieve(int n) {
	bool primes[n + 1];
	//Set all the elemnts of array primes to true
	memset(primes, true, sizeof(primes));
	for (int i = 2; i * i <= n; i++) {
		if (primes[i] == 1) {
			//Set the multiples of prime numbers to zero as the multiples of primes are not primes
			for (int j = i * i; j <= n; j += i) {
				primes[j] = 0;
			}
		}
	}
	//Printing all the prime numbers less than equal to n
	for (int i = 2; i <= n; i++) {
		if (primes[i])
			cout << i << " ";
	}
	cout << "\n";
}
int main() {
	int n = 50;
	sieve(n);
	return 0;
}