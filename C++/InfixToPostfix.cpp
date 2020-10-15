#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
bool isoperator(char s){
	if(s=='+'||s=='^'||s=='/'||s=='*'||s=='-')
	return true;
	else return false;
}
bool isoppar(char s){
	if(s=='(')
	return  true;
	else return false;
}
bool isclospar(char s){
	if(s=='}')
	return true;
	else
	return false;
}
int precidence(char x){
	switch(x){
		case '+':return -3;
		break;
		case '-':return -3;
		break;
		case '*':return -2;
		break;
		case '/':return -2;
		break;
		case '^':return -1;
	}
}
string change(string s){
	string res=" ";
	stack<char>st;
	for(int i=0;i<s.length();i++){
	if(s[i]>='a'&&s[i]<='z'){
		res=res+s[i];
	}
	  else if(s[i]=='('){
		st.push(s[i]);
		}
	  else if(isoperator(s[i])){
			while(!st.empty()&&!isoppar(st.top())&&(precidence(s[i])<precidence(st.top()))){
				res=res+st.top();
				st.pop();
			}
			st.push(s[i]);
		}
       else if(s[i]==')'){
			while(!st.empty()&&!isoppar(st.top())){
				res=res+st.top();
				st.pop();
			}
			st.pop();
		}
	}
	while(!st.empty()){
		res=res+st.top();
		st.pop();
	}
	return res;
}

int main()
{
	cout<<change("((a+b)*c-d)*e");
	return 0;
}
