//반례: [(((]
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){

	while(1){
		char str[101];
		cin.getline(str, 101);

		if(str[0] == '.' && strlen(str) == 1) break;

		stack<char> s;
		bool flag = true;
		for(int i=0; i<(int)strlen(str); i++){
			if(str[i] == '(' || str[i] == '['){
				s.push(str[i]);
			}
			else if(str[i] == ')'){
				if(!s.empty() && s.top() == '(') s.pop();
				else{
					flag = false;
					break;
				}
			}
			else if(str[i] == ']'){
				if(!s.empty() && s.top() == '[') s.pop();
				else{
					flag = false;
					break;
				}
			}
		}
		if(s.empty() && flag) cout<<"yes"<<'\n';
		else cout<<"no"<<'\n';
	}

	return 0;
}

