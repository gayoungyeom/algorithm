#include <iostream>
using namespace std;

int d[1000001];

int dp(int n){
	d[1] = 1;
	d[2] = 2;
	for(int i=3; i<=n; i++)
		d[i] = (d[i-1] + d[i-2]) % 15746;
	return d[n];
}

int main(){
	int n;
	cin>>n;
	cout<<dp(n);
	return 0;
}
