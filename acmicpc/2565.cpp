#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int length[1001];
vector<pair<int, int>> v;

int LIS(int n){
	int ans = 1;
	length[0] = 1;
	for(int i=1; i<n; i++){
		int max = 0;
		for(int j=i-1; j>=0; j--){
			if(v[j].second<v[i].second && length[j]>max) max = length[j];
		}
		length[i] = max + 1;
		if(length[i] > ans) ans = length[i];
	}
	return ans;
}

int main(){
	int n, a, b;
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>a>>b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	cout<<n - LIS(n)<<'\n';

	return 0;
}

