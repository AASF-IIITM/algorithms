// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to create Sieve for Semi Prime Numbers 
vector<int> createSemiPrimeSieve(int n) 
{ 
	int v[n + 1]; 

	// This array will initially store the indexes 
	// After performing below operations if any 
	// element of array becomes 1 this means 
	// that the given index is a semi-prime number 

	// Storing indices in each element of vector 
	for (int i = 1; i <= n; i++) 
		v[i] = i; 

	int countDivision[n + 1]; 

	for (int i = 0; i < n + 1; i++) 
		countDivision[i] = 2; 

	// This array will initially be initialized by 2 and 
	// will just count the divisions of a number 
	// As a semiprime number has only 2 prime factors 
	// which means after dividing by the 2 prime numbers 
	// if the index countDivision[x] = 0 and v[x] = 1 
	// this means that x is a semiprime number 

	// If number a is prime then its 
	// countDivision[a] = 2 and v[a] = a 

	for (int i = 2; i <= n; i++) { 

		// If v[i] != i this means that it is 
		// not a prime number as it contains 
		// a divisor which has already divided it 
		// same reason if countDivision[i] != 2 

		if (v[i] == i && countDivision[i] == 2) { 

			// j goes for each factor of i 
			for (int j = 2 * i; j <= n; j += i) { 
				if (countDivision[j] > 0) { 

					// Dividing the number by i 
					// and storing the dividend 
					v[j] = v[j] / i; 

					// Decreasing the countDivision 
					countDivision[j]--; 
				} 
			} 
		} 
	} 

	// A new vector to store all Semi Primes 
	vector<int> res; 

	for (int i = 2; i <= n; i++) { 

		// If a number becomes one and 
		// its countDivision becomes 0 
		// it means the number has 
		// two prime divisors 
		if (v[i] == 1 && countDivision[i] == 0) 
			res.push_back(i); 
	} 

	return res; 
} 

// Driver code 
int main() 
{ 
	int n = 200; 
	vector<int> semiPrime = createSemiPrimeSieve(n); 

	// Print all semi-primes 
	for (int i = 0; i < semiPrime.size(); i++) 
		cout << semiPrime[i] << " ,"; 

	return 0; 
} 

