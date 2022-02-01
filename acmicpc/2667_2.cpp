#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
char a[26][26];
bool visited[26][26];
vector<int> ans;
int depth;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

//단지 번호를 실제로 붙이기 위해서는 cnt 인자 추가하고, visited에 cnt를 넣어주면 됨.
void bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if(a[nx][ny] == '1' && !visited[nx][ny]){
				//정점 (nx, ny)을 방문할 때 필요한 작업 처리
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				depth++;
			}
		}
	}
}

int main(){
	cin>>n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j] == '1' && !visited[i][j]){
				depth = 1; //초기화
				bfs(i, j);
				ans.push_back(depth);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout<<ans.size()<<'\n';
	for(int i=0; i<(int)ans.size(); i++)
		cout<<ans[i]<<"\n";

	return 0;
}

