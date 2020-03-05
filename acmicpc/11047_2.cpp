#include <iostream>
using namespace std;

int A[1000001];

int main(){
	int n, k;
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>A[i];

	int cnt = 0;
	for(int i=n; i>0; i--){
		if(k - A[i] >= 0){
			cnt += k / A[i];
			k %= A[i];
		}
	}

	cout<<cnt<<'\n';

	return 0;
}

