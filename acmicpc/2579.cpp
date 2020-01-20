/*
 * f[n]: n개의 계단을 오르는데 얻는 최댓값
 * stair[n]: n번째 계단의 점수
 */
#include <iostream>
using namespace std;

int f[302];
int stair[302];

int dp(int n){
	if(n == 1) return stair[1];
	if(n == 2) return stair[1] + stair[2];
	if(n == 3) return max(stair[1], stair[2]) + stair[3];
	if(f[n] != 0) return f[n];
	f[n] = max(dp(n-3) + stair[n-1], dp(n-2)) + stair[n];
	return f[n];
}

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>stair[i];

	cout<<dp(n);

	return 0;
}

