#include <iostream>
using namespace std;

int f[11];

int dp(int n){
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(n == 3) return 4;
	if(f[n] != 0) return f[n];
	return f[n] = dp(n-1) + dp(n-2) + dp(n-3);
}

int main(){
	int test_case;
	int n;
	cin>>test_case;
	for(int i=0; i<test_case; i++){
		cin>>n;
		cout<<dp(n)<<endl;
	}
	return 0;
}
