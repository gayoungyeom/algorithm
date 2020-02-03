#include <iostream>
using namespace std;

int main(){
	int T, r;
	string s;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>r>>s;
		for(unsigned int j=0; j<s.size(); j++)
			for(int k=0; k<r; k++)
				cout<<s[j];
		cout<<endl;
	}

	return 0;
}
