#include <iostream>
#include <algorithm>
using namespace std;

int alpha[26];

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		string s;
		cin>>s;

		int now = 1;
		for(int j=s.length()-1; j>=0; j--){
			alpha[s[j]-'A'] += now;
			now *= 10;
		}
	}

	sort(alpha, alpha + 26);

	int ans = 0;
	int d = 9;
	for(int i=25; i>=0; i--){
		if(alpha[i] != 0)
			ans += (alpha[i] * d--);
	}

	cout<<ans<<'\n';

	return 0;
}

