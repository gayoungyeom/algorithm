#include <iostream>
using namespace std;

int f[31];

void dp(int n){
	f[0] = 1;
	f[2] = 3;
	for(int i=4; i<=n; i++){
		for(int j=4; j<=i; j+=2)
			f[i] += 2*f[i-j];
		f[i] += 3*f[i-2];
	}
}

int main(){
	int n;
	cin>>n;

	dp(n);
	cout<<f[n]<<'\n';

	return 0;
}
