#include <iostream>
using namespace std;

const int MAX = 1000001;
long long f[MAX];
long long g[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i=1; i<MAX; i++){ //i는 약수로 갖는 수
		for(int j=1; i*j<MAX; j++){ //i의 배수
			f[i*j] += i;
		}
	}

	g[1] = f[1];
	for(int i=2; i<1000001; i++){
		g[i] = g[i-1] + f[i];
	}

	int t, n;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>n;
		cout<<g[n]<<'\n';
	}

	return 0;
}
