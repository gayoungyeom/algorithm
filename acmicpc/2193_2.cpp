#include <iostream>
using namespace std;

long long f[101][2]; //f[n][i]: i로 끝나는 n자리 이친수 개수 (범위 잘 확인하기)

void dp(int n){
	f[1][1] = 1;
	for(int i=2; i<=n; i++){
		f[i][0] = f[i-1][0] + f[i-1][1];
		f[i][1] = f[i-1][0];
	}
}

int main(){
	int n;
	cin>>n;

	dp(n);
	cout<<f[n][0] + f[n][1]<<'\n';

	return 0;
}
