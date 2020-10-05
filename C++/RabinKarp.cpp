void rabinkarp(string const&p, string const&s) {
	// precalculate powers if length is within boundaries
	long long m=1e9+9;
	long long power=1, pp=53;
	long long pn=p.length();
	long long sn=s.length();
	long long h_p=rollinghash(p);
	vector<long long > v(sn+1, 0);
	for(long long i=0; i<sn; i++) {
		v[i+1]=v[i]+((s[i]-'a'+1)*power)%m;
		power=(power*pp)%m;
	}
	power=1;
	for(long long i=0; i<sn-pn+1; i++) {
		long long curr = (v[i+pn]+m-v[i])%m;
		if(curr==h_p*power%m) {
			// occurence index
			cout<<i<<"\n";
		}
		power=(power*pp)%m;
	}
}
