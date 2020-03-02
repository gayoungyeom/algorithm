//n번째 포도주를 꼭 마시지 않아도 된다는 것이 핵심
#include <iostream>
using namespace std;

int f[10001];
int wine[10001];

int dp(int n){
	f[0] = wine[0];
	f[1] = wine[0] + wine[1];
	f[2] = max(max(wine[0], wine[1]) + wine[2], f[1]);
	for(int i=3; i<n; i++){
		f[i] = max(max(f[i-2], f[i-3] + wine[i-1]) + wine[i], f[i-1]);
	}
	return f[n-1];
}

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>wine[i];

	cout<<dp(n);

	return 0;
}

