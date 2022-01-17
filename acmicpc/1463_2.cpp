#include <iostream>
using namespace std;

int f[1000001];

int dp(int n){
	f[1] = 0;
	f[2] = f[3] = 1;
	for(int i=4; i<=n; i++){
		f[i] = f[i-1] + 1;
		if(i % 2 == 0)
			f[i] = min(f[i], f[i/2] + 1);
		if(i % 3 == 0)
			f[i] = min(f[i], f[i/3] + 1);
	}
	return f[n];
}

int main(){
	int n;
	cin>>n;
	cout<<dp(n)<<'\n';
	return 0;
}

