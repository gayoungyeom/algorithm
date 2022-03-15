#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int k, w, h;
int a[201][201];
int dist[201][201][31];
queue<tuple<int, int, int>> q;

//말의 이동
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

//상하좌우
int dx2[] = {-1, 1, 0, 0};
int dy2[] = {0, 0, -1, 1};

void bfs(){
	q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 0;

	while(!q.empty()){
		int x, y, z;
		tie(x, y, z)= q.front();
		q.pop();

		for(int i=0; i<8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;

			if(a[nx][ny] == 0 && z < k && dist[nx][ny][z+1] == -1){
				dist[nx][ny][z+1] = dist[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z+1));
			}
		}

		for(int i=0; i<4; i++){
			int nx = x + dx2[i];
			int ny = y + dy2[i];

			if(nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;

			if(a[nx][ny] == 0 && dist[nx][ny][z] == -1){
				dist[nx][ny][z] = dist[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
		}

	}
}

int main(){
	cin>>k>>w>>h;
	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			cin>>a[i][j];

	memset(dist, -1, sizeof(dist));
	bfs();

	int ans = -1;
	for(int i=0; i<=k; i++){
		if(dist[h-1][w-1][i] != -1){
			if(ans == -1) ans = dist[h-1][w-1][i];
			else ans = min(ans, dist[h-1][w-1][i]);
		}
	}
	cout<<ans<<'\n';

	return 0;
}

