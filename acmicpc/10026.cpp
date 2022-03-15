#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, ans;
char a[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y){
	q.push(make_pair(x, y));
	visited[x][y] = true;
	ans++;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if(!visited[nx][ny] && a[nx][ny] == a[x][y]){
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j])
				bfs(i, j);
		}
	}
	cout<<ans<<' ';

	memset(visited, false, sizeof(visited));
	ans = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j] == 'G') a[i][j] = 'R';
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j])
				bfs(i, j);
		}
	}
	cout<<ans<<'\n';

	return 0;
}

