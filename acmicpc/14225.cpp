#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[20];
vector<int> v;

void go(int idx, int sum){
	if(idx == n){
		v.push_back(sum);
		return;
	}
	go(idx + 1, sum + a[idx]);
	go(idx + 1, sum);
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];

	go(0, 0);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int m = 0;
	for(int i=0; i<(int)v.size(); i++){
		if(v[i] != m) break;
		m++;
	}
	cout<<m<<'\n';

	return 0;
}

