#include <iostream>
using namespace std;

int f[100001];

void dp(int n){
	for(int i=1; i<=n; i++){
		f[i] = i; //마지막 항이 1인 경우 초기화
		for(int j=1; j*j <= i; j++){
			f[i] = min(f[i], f[i-j*j] + 1);
		}
	}
}

int main(){
	int n;
	cin>>n;

	dp(n);
	cout<<f[n]<<"\n";

	return 0;
}
