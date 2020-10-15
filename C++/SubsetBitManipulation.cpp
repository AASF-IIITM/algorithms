#include <bits/stdc++.h> 
using namespace std; 


vector<string> split(const string &s, char delim) 
{ 
	vector<string> elems; 
	stringstream ss(s); 
	string item; 
	while (getline(ss, item, delim)) 
		elems.push_back(item); 

	return elems; 
} 


int printPowerSet(int arr[], int n) 
{ 
	vector<string> list; 


	for (int i = 0; i < (int) pow(2, n); i++) 
	{ 
		string subset = ""; 

		for (int j = 0; j < n; j++) 
		{ 
	
			if ((i & (1 << j)) != 0) 
				subset += to_string(arr[j]) + "|"; 
		} 

		
		if (find(list.begin(), list.end(), subset) == list.end()) 
			list.push_back(subset); 
	} 


	for (string subset : list) 
	{ 
		
		vector<string> arr = split(subset, '|'); 
		for (string str: arr) 
			cout << str << " "; 
		cout << endl; 
	} 
} 


int main() 
{ 
	int arr[] = { 10, 12, 12 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	printPowerSet(arr, n); 

	return 0; 
} 
