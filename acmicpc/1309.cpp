#include <iostream>
using namespace std;

const int mod = 9901;
int f[1000001][3];

void dp(int n){
	f[1][0] = f[1][1] = f[1][2] = 1;
	for(int i=2; i<=n; i++){
		f[i][0] = (f[i-1][0] + f[i-1][1] + f[i-1][2]) % mod;
		f[i][1] = (f[i-1][0] + f[i-1][2]) % mod;
		f[i][2] = (f[i-1][0] + f[i-1][1]) % mod;
	}
}

int main(){
	int n;
	cin>>n;

	dp(n);
	cout<<(f[n][0] + f[n][1] + f[n][2]) % mod<<'\n';

	return 0;
}
