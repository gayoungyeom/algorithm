#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[16];
int n, l, r, x, ans;
bool check[16];

void go(int idx, int cur, int m, vector<int>& v){
	if(idx == m){
		int sum = 0;
		for(int i=0; i<m; i++)
			sum += v[i];
		if(l <= sum && sum <= r && v[m-1] - v[0] >= x)
			ans++;
		return;
	}

	for(int i=cur; i<n; i++){
		if(!check[i]){
			check[i] = true;
			v.push_back(a[i]);
			go(idx+1, i+1, m, v);
			v.pop_back();
			check[i] = false;
		}
	}
}

int main(){
	cin>>n>>l>>r>>x;

	for(int i=0; i<n; i++)
		cin>>a[i];

	sort(a, a+n);

	for(int i=2; i<=n; i++){ //i: 문제 수
		vector<int> v;
		go(0, 0, i, v);
	}

	cout<<ans<<'\n';

	return 0;
}

