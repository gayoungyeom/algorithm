#include <iostream>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	int ans = 0;
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum += a[j];
			if(sum == m){
				ans++;
				break;
			}
		}
	}

	cout<<ans<<'\n';

	return 0;
}

