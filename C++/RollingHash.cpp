long long rollinghash(string s) {
	const int p = 53;
	const long long m = 1e9 + 9;
	long long hashvalue = 0;
	long long power = 1;
	for (char c : s) {
		hashvalue = (hashvalue + (c - 'a' + 1) * power) % m;
		power = (power * p) % m;
	}
	return hashvalue;
}
