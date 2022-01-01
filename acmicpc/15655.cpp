#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> arr;
bool visited[10];

void backtrack(int idx, int n, int m){
	if((int)v.size() == m){ //재귀 종료 조건
		for(int i=0; i<m; i++)
			cout<<v[i]<<" ";
		cout<<'\n';
		return;
	}
	for(int i=idx; i<n; i++){
		v.push_back(arr[i]);
		backtrack(i+1, n, m);
		v.pop_back();
	}
}

int main(){
	int n, m;
	cin>>n>>m;

	int x;
	for(int i=0; i<n; i++){
		cin>>x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	backtrack(0, n, m);

	return 0;
}

