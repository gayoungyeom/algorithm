#include <iostream>
#include <stack>
using namespace std;

int main(){
	int T;
	cin>>T;

	string ps;
	for(int i=0; i<T; i++){
		cin>>ps;
		stack<char> s;
		bool flag = true;
		int size = ps.size();
		for(int j=0; j<size; j++){
			if(ps[j] == '('){
				s.push('(');
			}
			else{
				if(!s.empty()) s.pop();
				else flag = false;
			}
		}
		if(s.empty() && flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}

	return 0;
}

