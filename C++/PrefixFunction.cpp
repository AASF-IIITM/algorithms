int piarr[100005];
void prefixFunction(string s, int n) {
	piarr[0]=0;
	for(int i=1; i<n; i++) {
		int l=piarr[i-1];
		while(l>0 && (s[i]!=s[l]))  {
			l=piarr[l-1];
		}
		if(s[i]==s[l]) {
			l=l+1; 
		}
		piarr[i]=l;
	}
}
