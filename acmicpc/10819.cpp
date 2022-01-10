#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr, arr + n);

	int ans = 0;
	do{
		int sum = 0;
		for(int i=0; i<n-1; i++){
			int sub = arr[i] - arr[i+1];
			if(sub < 0) sub = -sub;
			sum += sub;
		}
		ans = max(ans, sum);
	} while(next_permutation(arr, arr + n));

	cout<<ans<<'\n';

	return 0;
}
