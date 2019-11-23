#include <iostream>
using namespace std;

int f[11];

int dp(int n){
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	for(int i=4; i<=n; i++)
		f[i] = f[i-1] + f[i-2] + f[i-3];
	return f[n]; 
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
