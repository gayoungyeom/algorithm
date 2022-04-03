#include <iostream>
#include <cstring>
using namespace std;

int r, c;
int a[501][501];
int cnt[501][501];
pair<int, int> log[501][501];

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

pair<int, int> dfs(int x, int y){
	if(log[x][y].first != -1) return log[x][y];

	bool stop = true;
	pair<int, int> mv;
	int minval = a[x][y];

	for(int i=0; i<8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;

		if(a[x][y] > a[nx][ny]){
			stop = false;
			if(minval > a[nx][ny]){
				mv.first = nx;
				mv.second = ny;
				minval = a[nx][ny];
			}
		}
	}
	if(stop)
		return {x, y};
	else
		return log[x][y] = dfs(mv.first, mv.second); //log[x][y]에 값을 넣고 dfs호출해야 시간초과가 나지 않음! (memoization)
}

int main(){
	cin>>r>>c;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			cin>>a[i][j];

	memset(log, -1, sizeof(log));
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			pair<int, int> p = dfs(i, j);
			cnt[p.first][p.second]++;
		}
	}

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cout<<cnt[i][j]<<" ";
		cout<<'\n';
	}

	return 0;
}

