#include <iostream>
using namespace std;

const int mod = 1000000000;
int f[201][201];

void dp(int n, int k){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=k; j++){
			if(i == 0 || j == 1){
				f[i][j] = 1;
				continue;
			}
			for(int l=0; l<=i; l++){
				f[i][j] += f[i-l][j-1];
				f[i][j] %= mod;
			}
		}
	}
}

int main(){
	int n, k;
	cin>>n>>k;

	dp(n, k);
	cout<<f[n][k]<<'\n';

	return 0;
}
