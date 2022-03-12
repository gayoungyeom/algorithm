#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
int a[10][10];
int b[10][10];
vector<pair<int, int>> v;
queue<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(){
	for(int i=0; i<(int)v.size(); i++) //모든 2를 큐에 넣고 시작해야 함
		q.push(make_pair(v[i].first, v[i].second));

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if(b[nx][ny] == 0){
				b[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void wall(int cnt){
	if(cnt == 3){
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				b[i][j] = a[i][j];

		bfs();

		int cnt = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(b[i][j] == 0)
					cnt++;
			}
		}
		ans = max(ans, cnt);
		return;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] == 0){
				a[i][j] = 1;
				wall(cnt+1);
				a[i][j] = 0;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j] == 2)
				v.push_back(make_pair(i, j));
		}
	}

	//3개의 벽을 세우는 모든 경우
	wall(0);

	cout<<ans<<'\n';

	return 0;
}

