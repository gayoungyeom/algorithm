#include <iostream>
using namespace std;

const int mod = 10007;
int f[1001][10];

void dp(int n){
	f[0][0] = 1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<=j; k++)
				f[i][j] += f[i-1][k];
			f[i][j] %= mod;
		}
	}
}

int main(){
	int n;
	cin>>n;

	dp(n);

	int ans = 0;
	for(int i=0; i<10; i++)
		ans += f[n][i];
	cout<<ans%mod<<'\n';

	return 0;
}
