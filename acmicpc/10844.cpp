/*
 * f[i][j]: 길이가 i인 계단에서 j로 끝나는 경우의 계단 수
 */
#include <iostream>
using namespace std;

int f[101][11];

int dp(int n){
	for(int j=1; j<=9; j++)
		f[1][j] = 1;

	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			if(j == 0) f[i][j] = f[i-1][j+1];
			else if(j == 9) f[i][j] = f[i-1][j-1];
			else f[i][j] = (f[i-1][j-1] + f[i-1][j+1]) % 1000000000;
		}
	}

	int sum = 0;
	for(int i=0; i<=9; i++){
		sum = (sum + f[n][i]) % 1000000000;
	}
	return sum;
}

int main(){
	int n;
	cin>>n;

	cout<<dp(n);

	return 0;
}
