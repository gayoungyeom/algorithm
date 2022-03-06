#include <iostream>
using namespace std;

int main(){
	int n, s;
	cin>>n>>s;

	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	int left = 0;
	int right = 0;
	int sum = a[0];
	int ans = n+1;

	while(left <= right && right < n){
		if(sum < s){
			right++;
			sum += a[right];
		} else if(sum == s){
			ans = min(ans, right-left+1);
			right++;
			sum += a[right];
		} else if (sum > s){
			ans = min(ans, right-left+1);
			sum -= a[left];
			left++;
//			if(left > right && left < n){ -> 이 부분 없어도 정답
//				right = left;
//				sum = a[left];
//			}
		}
	}

	if(ans == n+1) cout<<0<<'\n';
	else cout<<ans<<'\n';

	return 0;
}

