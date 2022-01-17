#include <iostream>
using namespace std;

int f[4][100001]; //f[k][i]: 마지막에 k를 사용해서 i를 만드는 방법의 수

void dp(int n){
	f[1][1] = f[2][2] = f[3][3] = 1;
	f[1][3] = f[2][3] = 1;
	for(int i=4; i<=n; i++){
		f[1][i] = (f[2][i-1] + f[3][i-1]) % 1000000009;
		f[2][i] = (f[1][i-2] + f[3][i-2]) % 1000000009;
		f[3][i] = (f[1][i-3] + f[2][i-3]) % 1000000009;
	}
}

int main(){
	int t, n;
	cin>>t;

	dp(100000);

	while(t--){
		cin>>n;
		long long sum = 0;
		for(int i=1; i<=3; i++)
			sum += f[i][n];
		cout<<sum%1000000009<<'\n';
	}
	return 0;
}

