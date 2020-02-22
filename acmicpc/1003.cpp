#include <iostream>
using namespace std;

pair<int, int> f[50];

void fib(long long n) {
	f[0].first = 1;
	f[0].second = 0;
	for(int i=1; i<=n; i++){
		f[i].first = f[i-1].second;
		f[i].second = f[i-1].first + f[i-1].second;
	}
}

int main(){
	int n, T;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>n;
		fib(n);
		cout<<f[n].first<<" "<<f[n].second<<'\n';
	}
	return 0;
}

