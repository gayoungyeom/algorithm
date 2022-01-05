#include <iostream>
using namespace std;

int go(int sum, int n){
	if(sum > n) return 0;
	if(sum == n) return 1;
	int cnt = 0;
	for(int i=1; i<=3; i++)
		cnt += go(sum + i, n);
	return cnt;
}

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n;
		cin>>n;
		cout<<go(0, n)<<'\n';
	}
	return 0;
}

