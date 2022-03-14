#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
int a[1001][1001];
int dist[1001][1001][11]; //dist[x][y][k]에서 k는 벽을 부순 횟수
queue<tuple<int, int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(){
	q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 1;

	while(!q.empty()){
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if(a[nx][ny] == 0 && dist[nx][ny][z] == 0){ //빈 칸인 경우
				dist[nx][ny][z] = dist[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
			if(a[nx][ny] == 1 && z < k && dist[nx][ny][z+1] == 0){ //벽을 부술 수 있는 경우
				dist[nx][ny][z+1] = dist[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z+1));
			}
		}
	}
}

int main(){
	cin>>n>>m>>k;

	char c;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>c;
			a[i][j] = c - '0';
		}
	}

	bfs();

	int ans = -1;
	for(int i=0; i<=k; i++){
		if(dist[n-1][m-1][i] != 0){
			if(ans == -1) ans = dist[n-1][m-1][i];
			else ans = min(ans, dist[n-1][m-1][i]);
		}
	}
	cout<<ans<<'\n';

	return 0;
}

