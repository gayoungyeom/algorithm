#include <iostream>
using namespace std;

int f[1001];
int p[10001];

int dp(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			f[i] = max(f[i], f[i-j] + p[j]);
		}
	}
	return f[n];
}

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>p[i];
	cout<<dp(n)<<'\n';
	return 0;
}
