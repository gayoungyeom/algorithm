#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int a[51][51];
int dist[51][51];
queue<pair<int, int>> q;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(){
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if(a[nx][ny] == 0 && dist[nx][ny] == -1){
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(){
	cin>>n>>m;
	memset(dist, -1, sizeof(dist));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j] == 1){
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}

	bfs();

	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(dist[i][j] == 0) continue;
			ans = max(ans, dist[i][j]);
		}
	}
	cout<<ans<<'\n';

	return 0;
}

