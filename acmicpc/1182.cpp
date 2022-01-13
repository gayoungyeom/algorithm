#include <iostream>
using namespace std;

int main(){
	int n, s;
	cin>>n>>s;

	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];

	int bs = (1<<n) - 1;
	int ans = 0;

	for(int i=1; i<=bs; i++){
		int sum = 0;
		for(int j=0; j<n; j++){
			//비트마스크 i에 j가 들어있는지 check
			int check = (i&(1<<j));
			if(check) sum += arr[j];
		}
		if(sum == s) ans++;
	}

	cout<<ans<<'\n';
	
	return 0;
}
