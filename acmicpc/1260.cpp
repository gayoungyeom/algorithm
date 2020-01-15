#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[100001];
bool visited[100001];
vector<int> dfsRoute;
vector<int> bfsRoute;

void dfs(int cur){
	visited[cur] = true;
	dfsRoute.push_back(cur);
	for(unsigned int i=0; i<v[cur].size(); i++){
		if(!visited[v[cur][i]]){
			dfs(v[cur][i]);
		}
	}
}

void bfs(int cur){
	queue<int> q;
	q.push(cur);
	visited[cur] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		bfsRoute.push_back(x);
		for(unsigned int i=0; i<v[x].size(); i++){
			if(!visited[v[x][i]]){
				q.push(v[x][i]);
				visited[v[x][i]] = true;
			}
		}
	}
}


int main(){
	int N, M, V;
	int v1, v2;

	cin>>N>>M>>V;
	for(int i=0; i<M; i++){
		cin>>v1>>v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	//방문할 수 있는 정점의 여러 개인 경우 정점 번호가 작은 것 먼저 방문하도록 정렬
	for(int i=0; i<=M; i++)
		sort(v[i].begin(), v[i].end());

	//dfs 수행 결과 출력
	dfs(V);
	for(unsigned int i=0; i<dfsRoute.size(); i++)
		cout<<dfsRoute[i]<<" ";

	//dfs에서 사용한 visited 초기화
	for(int i=0; i<=N; i++)
		visited[i] = false;
	cout<<endl;

	//bfs 수행 결과 출력
	bfs(V);
	for(unsigned int i=0; i<bfsRoute.size(); i++)
		cout<<bfsRoute[i]<<" ";

	return 0;
}
