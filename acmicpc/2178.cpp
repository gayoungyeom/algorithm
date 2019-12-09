#include <iostream>
#include <queue>
using namespace std;

int main(){
	queue<pair<int, int>> q;
	//오른, 아래, 왼, 위
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int m, n;
	char c;

	cin>>m>>n;
	int maze[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>c;
			maze[i][j] = c - 48;
		}
	}

	q.push({0, 0});

	while(!q.empty()){ //더이상 탐색할 것이 없을 때까지
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || ny < 0 || nx >= m || ny >= n) //경계 제어
				continue;

			if(maze[nx][ny] == 1){
				q.push({nx, ny});
				maze[nx][ny] = maze[x][y] + 1;
			}
		}
	}

	cout<<maze[m-1][n-1]<<endl;

	return 0;
}

