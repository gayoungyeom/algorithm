#include <iostream>
using namespace std;

pair<long long, long long> zeroCnt(long long n){
	long long two = 0, five = 0;
	for(long long i=2; i<=n; i*=2)
		two += n/i;
	for(long long i=5; i<=n; i*=5)
		five += n/i;
	return (make_pair(two, five));
}

int main(){
	long long n, m;
	cin>>n>>m;

	int two = zeroCnt(n).first - zeroCnt(n-m).first - zeroCnt(m).first;
	int five = zeroCnt(n).second - zeroCnt(n-m).second - zeroCnt(m).second;

	cout<<min(two, five);

	return 0;
}

