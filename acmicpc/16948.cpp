#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, r1, c1, r2, c2;
int dist[201][201];
queue<pair<int, int>> q;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

void bfs(int r1, int c1){
	q.push(make_pair(r1, c1));
	dist[r1][c1] = 0;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<6; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if(dist[nx][ny] == -1){
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(){
	cin>>n;
	cin>>r1>>c1>>r2>>c2;
	memset(dist, -1, sizeof(dist));

	bfs(r1, c1);

	cout<<dist[r2][c2]<<'\n';

	return 0;
}

