#include <iostream>
using namespace std;

int f[3000003];

int dp(int x){
	for(int i=1; i<1000001; i++){
		if(!f[i+1])	f[i+1] = f[i] + 1;
		else f[i+1] = min(f[i+1], f[i] + 1);

		if(!f[i*2])	f[i*2] = f[i] + 1;
		else f[i*2] = min(f[i*2], f[i] + 1);

		if(!f[i*3]) f[i*3] = f[i] + 1;
		else f[i*3] = min(f[i*3], f[i] + 1);
	}
	return f[x];
}

int main(){
	int x;
	cin>>x;
	cout<<dp(x);
	return 0;
}
