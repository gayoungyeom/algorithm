#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char a[501][501];
bool check[501][501];
int isexit[501][501];

void print_exit(vector<pair<int, int>> v){
	for(int i=0; i<(int)v.size(); i++)
		isexit[v[i].first][v[i].second] = 1;
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(isexit[i][j] == 1) continue;

			vector<pair<int, int>> v;
			queue<pair<int, int>> q;
			q.push({i, j});
			check[i][j] = true;

			while(!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				v.push_back({x, y});

				if(a[x][y] == 'U'){
					int nx = x -1;
					int ny = y;

					if(nx < 0 || nx >= n || ny < 0 || ny >= m){ //탈출
						print_exit(v);
					} else{
						if(!check[nx][ny]){
							q.push({nx, ny});
							check[nx][ny] = true;
						} else if(isexit[nx][ny] == 1){ //방문했는데 탈출 가능한 칸인 경우
							print_exit(v);
						}
					}
				} else if(a[x][y] == 'R'){
					int nx = x;
					int ny = y + 1;
					if(nx < 0 || nx >= n || ny < 0 || ny >= m){ //탈출
						print_exit(v);
					} else{
						if(!check[nx][ny]){
							q.push({nx, ny});
							check[nx][ny] = true;
						} else if(isexit[nx][ny] == 1){
							print_exit(v);
						}
					}
				} else if(a[x][y] == 'D'){
					int nx = x + 1;
					int ny = y;
					if(nx < 0 || nx >= n || ny < 0 || ny >= m){ //탈출
						print_exit(v);
					} else{
						if(!check[nx][ny]){
							q.push({nx, ny});
							check[nx][ny] = true;
						} else if(isexit[nx][ny] == 1){
							print_exit(v);
						}
					}
				} else if(a[x][y] == 'L'){
					int nx = x;
					int ny = y - 1;
					if(nx < 0 || nx >= n || ny < 0 || ny >= m){ //탈출
						print_exit(v);
					} else{
						if(!check[nx][ny]){
							q.push({nx, ny});
							check[nx][ny] = true;
						} else if(isexit[nx][ny] == 1){
							print_exit(v);
						}
					}
				}
			}
		}
	}

	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(isexit[i][j] == 1) ans++;
		}
	}
	cout<<ans<<'\n';

	return 0;
}

