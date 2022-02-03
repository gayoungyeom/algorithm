#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;
int a[MAX][MAX];
int dist[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
	int m, n;
	cin>>m>>n;

	char c;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>c;
			a[i][j] = c - 48;
		}
	}

	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	q.push(make_pair(0, 0));
	dist[0][0] = 1;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if(!dist[nx][ny]){
				if(a[nx][ny]){ //벽
					nq.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
				} else{ //빈방
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y];
				}
			}
		}
		if(q.empty()){
			q = nq;
			nq = queue<pair<int, int>>();
		}
	}

	cout<<dist[n-1][m-1] - 1<<'\n';

	return 0;
}

