#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[12], op[4];
vector<int> v;

void go(int idx, int plus, int min, int mul, int div, int sum){
	if(idx == n-1){
		v.push_back(sum);
		return;
	}

	if(plus > 0) go(idx+1, plus-1, min, mul, div, sum+a[idx+1]);
	if(min > 0) go(idx+1, plus, min-1, mul, div, sum-a[idx+1]);
	if(mul > 0) go(idx+1, plus, min, mul-1, div, sum*a[idx+1]);
	if(div > 0) go(idx+1, plus, min, mul, div-1, sum/a[idx+1]);
}

int main(){
	cin>>n;

	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<4; i++)
		cin>>op[i];

	go(0, op[0], op[1], op[2], op[3], a[0]);

	sort(v.begin(), v.end());

	cout<<v[v.size()-1]<<'\n';
	cout<<v[0]<<'\n';

	return 0;
}

