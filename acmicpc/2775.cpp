#include <iostream>
using namespace std;

int d[15][15];

int dp(int k, int n){
	for(int i=1; i<=n; i++)
		d[0][i] = i;

	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			d[i][j] = d[i-1][j] + d[i][j-1];
		}
	}
	return d[k][n];
}

int main(){
	int T, k, n;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>k>>n;
		cout<<dp(k, n)<<endl;
	}
	return 0;
}

