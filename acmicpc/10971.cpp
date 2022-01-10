#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;

	int w[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>w[i][j];

	int arr[n];
	for(int i=0; i<n; i++)
		arr[i] = i;

	int ans = 10000000;
	do {
		int cost = 0;
		bool flag = true;
		for(int i=0; i<n-1; i++){
			if(w[arr[i]][arr[i+1]] == 0){ //길이 없는 경우
				flag = false;
				break;
			}
			cost += w[arr[i]][arr[i+1]];
		}

		//처음 도시로 돌아옴
		int back = w[arr[n-1]][arr[0]];
		if(!back) flag = false;

		if(flag) ans = min(ans, cost + back);
	} while(next_permutation(arr, arr + n));

	cout<<ans<<'\n';

	return 0;
}
