#include <iostream>
#include <vector>
using namespace std;

vector<int> a[20001];
int color[20001]; //0: 방문x, 1: A, 2: B

bool dfs(int cur, int c){
	color[cur] = c;
	for(int i=0; i<(int)a[cur].size(); i++){
		if(color[a[cur][i]] == 0){
			if(!dfs(a[cur][i], 3-c)) return false;
		} else if(color[a[cur][i]] == color[cur]) {
			return false;
		}
	}
	return true;
}

int main(){
	int k;
	cin>>k;

	for(int i=0; i<k; i++){
		int V, E;
		cin>>V>>E;

		//초기화
		for(int j=1; j<=V; j++){
			a[j].clear();
			color[j] = 0;
		}

		for(int j=0; j<E; j++){
			int u, v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}

		bool flag = true;
		for(int i=1; i<=V; i++){
			if(color[i] == 0){
				if(!dfs(i, 1)) flag = false;
			}
		}
		cout<<(flag ? "YES" : "NO")<<'\n';
	}

	return 0;
}

