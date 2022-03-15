#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int f, s, g, u, d;
int dist[1000001];
queue<int> q;

void bfs(int cur){
	q.push(cur);
	dist[cur] = 0;

	while(!q.empty()){
		int x = q.front();
		q.pop();

		int ux = x + u;
		int dx = x - d;

		//경게 제어를 각각 해줘야 한다!!
		if(ux <= f && dist[ux] == -1){
			q.push(ux);
			dist[ux] = dist[x] + 1;
		}

		if(dx > 0 && dist[dx] == -1){
			q.push(dx);
			dist[dx] = dist[x] + 1;
		}
	}
}

int main(){
	cin>>f>>s>>g>>u>>d;
	memset(dist, -1, sizeof(dist));
	bfs(s);

	if(dist[g] == -1) cout<<"use the stairs"<<'\n';
	else cout<<dist[g]<<'\n';

	return 0;
}

