#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
bool visited[101];
int cnt;

void dfs(int cur){
	visited[cur] = true;
	cnt++;
	for(unsigned int i=0; i<v[cur].size(); i++){
		if(!visited[v[cur][i]]){
			dfs(v[cur][i]);
		}
	}
}


int main(){
	int n, m, v1, v2;
	cin>>n>>m;

	for(int i=0; i<m; i++){
		cin>>v1>>v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	dfs(1);
	cout<<cnt - 1;

	return 0;
}

