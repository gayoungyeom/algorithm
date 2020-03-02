#include <iostream>
using namespace std;

long long d[101];

long long dp(int n){
	if(n < 4) return 1;
	if(n < 6) return 2;
	if(d[n] != 0) return d[n];
	d[n] = dp(n-5) + dp(n-1);
	return d[n];
}

int main(){
	int T, n;
	cin>>T;
	for(int i=0; i<T; i++){
		cin>>n;
		cout<<dp(n)<<'\n';
	}
	return 0;
}

