/*
 * f[n]: n자리 이친수의 개수
 */
#include <iostream>
using namespace std;

long long int f[1001];

long long int dp(int n){
	f[1] = 1;
	f[2] = 1;
	for(int i=3; i<=n; i++)
		f[i] = f[i-1] + f[i-2];
	return f[n];
}

int main(){
	int N;
	cin>>N;
	cout<<dp(N);
	return 0;
}

/*
* 재귀적 정의:
* n자리 이친수 중 0으로 끝나는 이친수의 개수 = n-1자리 이친수의 개수
* n자리 이친수 중 1로 끝나는 이친수의 개수 = n-1자리 이친수 중 0으로 끝나는 이친수의 개수
* 즉, n자리 이친수의 개수 = n-1자리 이친수의 개수 + n-2자리 이친수의 개수
*/

