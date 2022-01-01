#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> arr;
bool visited[10]; //arr의 idx로 판단

void backtrack(int n, int m){
	if((int)v.size() == m){ //재귀 종료 조건
		for(int i=0; i<m; i++)
			cout<<v[i]<<" ";
		cout<<'\n';
		return;
	}
	for(int i=0; i<n; i++){
		if(!visited[i]){
			visited[i] = true;
			v.push_back(arr[i]);
			backtrack(n, m);
			visited[i] = false;
			v.pop_back();
		}
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
	backtrack(n, m);

	return 0;
}

