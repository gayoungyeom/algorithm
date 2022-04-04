#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ind[32001];
vector<int> v[32001];
queue<int> q;

void bfs(){
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout<<x<<" ";
		for(int i=0; i<(int)v[x].size(); i++){
			int y = v[x][i];
			ind[y]--; //간선 제거
			if(ind[y] == 0){
				q.push(y);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	while(m--){
		int a, b;
		cin>>a>>b;
		v[a].push_back(b);
		ind[b]++;
	}

	for(int i=1; i<=n; i++){
		if(ind[i] == 0){ //시작점
			q.push(i);
		}
	}

	bfs();

	return 0;
}

