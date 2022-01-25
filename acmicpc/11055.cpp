#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int f[1001];

void dp(int n){
	for(int i=0; i<n; i++){
		f[i] = a[i];
		for(int j=i; j>=0; j--){
			if(a[j] < a[i])
				f[i] = max(f[i], f[j] + a[i]);
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
		cin>>a[i];

	dp(n);

	int ans = *max_element(f, f + n);
	cout<<ans<<"\n";

	return 0;
}
