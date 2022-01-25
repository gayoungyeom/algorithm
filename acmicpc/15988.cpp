#include <iostream>
using namespace std;

const int mod = 1000000009;
long long f[1000001]; //d[i]의 합을 구하는 과정에서 int의 범위를 넘어가므로 long long 사용해야 함

void dp(){
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	for(int i=4; i<1000001; i++)
		f[i] = (f[i-1] + f[i-2] + f[i-3]) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n;
	cin>>t;

	dp();
	while(t--){
		cin>>n;
		cout<<f[n] % mod<<'\n';
	}

	return 0;
}

