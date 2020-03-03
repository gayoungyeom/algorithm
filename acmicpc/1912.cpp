#include <iostream>
using namespace std;

int num[100001];
int maxSum[100001];

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++)
		cin>>num[i];

	maxSum[0] = num[0];
	int ans = max(-1000, num[0]);
	for(int i=1; i<n; i++){
		if(maxSum[i-1] > 0) //이전 값이 양수인 경우
			maxSum[i] = maxSum[i-1] + num[i];
		else //이전 값이 음수인 경우
			maxSum[i] = num[i];

		if(maxSum[i] > ans) ans = maxSum[i];
	}

	cout<<ans<<'\n';

	return 0;
}

