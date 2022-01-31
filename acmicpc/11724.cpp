#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
bool visited[1001];

void dfs(int cur){
	visited[cur] = true;
	for(int i=0; i<(int)v[cur].size(); i++){
		if(!visited[v[cur][i]]){
			dfs(v[cur][i]);
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;

	int a, b;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt<<'\n';

	return 0;
}

