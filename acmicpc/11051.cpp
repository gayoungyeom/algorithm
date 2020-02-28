#include <iostream>
using namespace std;

int c[1001][1001];

int C(int n, int k){
	if(k == 0) return 1;
	if(n == k) return 1;
	if(c[n][k] != 0) return c[n][k];
	c[n][k] = (C(n-1, k) + C(n-1, k-1)) % 10007;
	return c[n][k];
}

int main(){
	int n, k;
	cin>>n>>k;
	cout<<C(n, k);
	return 0;
}

