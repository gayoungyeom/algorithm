#include <iostream>
using namespace std;

string s;
int a[4], ans;

void go(int idx, int n){
	if(idx == n){
		for(int i=0; i<n-1; i++){
			if(a[i] == a[i+1])
				return;
		}
		ans++;
		return;
	}

	if(s[idx] == 'c'){
		for(int j=0; j<26; j++){
			a[idx] = j + 97;
			go(idx+1, n);
		}
	} else{
		for(int j=0; j<=9; j++){
			a[idx] = j;
			go(idx+1, n);
		}
	}
}

int main(){
	cin>>s;
	go(0, s.length());
	cout<<ans<<'\n';
	return 0;
}

