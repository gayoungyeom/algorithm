#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char a[51][51];
bool visited[51][51];
int dist[51][51];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

//cnt: 지금까지 방문한 칸의 개수(중복 방문도 포함)
bool dfs(int x, int y, int cnt){
	if(visited[x][y]) //사이클 체크
		return cnt - dist[x][y] >= 4; //4칸 이상 체크

	visited[x][y] = true;
	dist[x][y] = cnt;

	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if(a[x][y] == a[nx][ny]){
			if(dfs(nx, ny, cnt+1))
				return true;
		}
	}
	return false;
}

int main(){
	cin>>n>>m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j]) continue;
			memset(dist, 0, sizeof(dist));
			bool ok = dfs(i, j, 1);
			if(ok){ //하나라도 나오면 더 볼 필요 없음
				cout<<"Yes"<<'\n';
				return 0;
			}
		}
	}

	cout<<"No"<<'\n';

	return 0;
}

