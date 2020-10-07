/* Trie Implementation

   A Trie is a special data structure used to store strings that can be visualized like a graph. It consists of nodes and edges. 
   Each node consists of at max 26 children and edges connect each parent node to its children.
   These 26 pointers are nothing but pointers for each of the 26 letters of the English alphabet A separate edge is maintained for every edge.
   
   Tries are generally used on groups of strings, rather than a single string. 
   When given multiple strings , we can solve a variety of problems based on them.
   
   For example - Consider we are given n strings. Then, we are asked q queries.
   In each query, we take a string as input and we have to tell whether any prefix of this string matches with prefix of any of the n given strings or not.
   
   Solving this problem using a naive approach would require us to match the prefix of the given string with the prefix of every other word.
   Tries can solve this problem in much more efficient way.

*/

#include<bits/stdc++.h>
using namespace std;

class tries{
	
	private:
		
		// Structure of a trie
		struct trie{
			struct trie* child[26];
			bool isend;
			trie()
			{
				memset(child,0,sizeof(child));
		        isend=false;
			}
		};
		
	    struct trie* root;
	
	public:
		
		tries()
		{
			root = new trie();
		}
		
		// Insertion of a string into a trie
		void insert(string word)
		{
			struct trie* curr = root;
			for(char ch:word)
			{
				int index = ch - 'a';
				
				if(curr->child[index] == NULL) curr->child[index] = new trie();
				
				curr = curr->child[index];
			}
			curr->isend = true;
		}
		
		// Function to check whether prefix matches or not with any of the strings
		bool prefix(string text)
		{
			struct trie* curr = root;
			for(char ch:text)
			{
				int index = ch - 'a';
				
				if(curr->child[index] == NULL) return false;
				
				curr = curr->child[index];
			}
			return true;
		}
} trieobj;

int main()
{
	int n;
	cin>>n;
	
	// Input n strings
	while(n--)
	{
		string word;
		cin>>word;
		trieobj.insert(word);
	}
	
	int q;
	cin>>q;
	
	// Queries
	while(q--)
	{
		string text;
		cin>>text;
		
		if(trieobj.prefix(text)) cout<<"Present\n";
		else cout<<"Not Present\n";
	}
	return 0;
}
