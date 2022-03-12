#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[101];
bool visited[101];
int dist[101];
queue<int> q;
bool rcheck[101];

void bfs(int cur){
	q.push(cur);
	visited[cur] = true;

	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0; i<(int)a[x].size(); i++){
			if(!visited[a[x][i]]){
				q.push(a[x][i]);
				visited[a[x][i]] = true;
				dist[a[x][i]] = min(dist[a[x][i]], dist[x] + 1);
			}
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;

	int x, y;
	for(int i=0; i<n; i++){
		cin>>x>>y;
		a[x].push_back(y);
		rcheck[x] = true;
	}
	for(int i=0; i<m; i++){
		cin>>x>>y;
		a[x].push_back(y);
		rcheck[x] = true;
	}

	for(int i=1; i<100; i++){
		if(!rcheck[i]){
			for(int j=1; j<=6; j++){
				if(rcheck[i+j]){
					if(a[i+j][0] <= 100)
						a[i].push_back(a[i+j][0]);
				} else{
					if(i+j <= 100)
						a[i].push_back(i+j);
				}
			}
		}
	}

	dist[1] = 0;
	for(int i=2; i<101; i++) dist[i] = 100;

	bfs(1);

	cout<<dist[100]<<'\n';

	return 0;
}

