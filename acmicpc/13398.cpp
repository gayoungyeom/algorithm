#include <iostream>
using namespace std;

int a[100001];
int fin[100001]; //i번째 수에서 끝나는 최대 연속합
int str[100001]; //i번째 수에서 시작하는 최대 연속합

void dp(int n){
	//fin 구하기
	fin[1] = a[1];
	for(int i=2; i<=n; i++)
		fin[i] = max(fin[i-1] + a[i], a[i]);

	//str 구하기
	str[n] = a[n];
	for(int i=n-1; i>=1; i--)
		str[i] = max(str[i+1] + a[i], a[i]);
}

int main(){
	int n;
	cin>>n;

	for(int i=1; i<=n; i++)
		cin>>a[i];

	dp(n);

	//수 제거하지 않는 경우 최대 합
	int ans = fin[1];
	for(int i=2; i<=n; i++)
		ans = max(ans, fin[i]);

	//어떤 수 제거한 경우 최대 합
	for(int i=2; i<=n-1; i++)
		ans = max(ans, fin[i-1] + str[i+1]);

	cout<<ans<<"\n";

	return 0;
}
