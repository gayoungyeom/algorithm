#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char a[26][26];
bool visited[26][26];
vector<int> ans;
int depth;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

//단지 번호를 실제로 붙이기 위해서는 cnt 인자 추가하면 됨.
void dfs(int x, int y){
	visited[x][y] = true;
	depth++;

	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || nx >= n || ny < 0 || ny >= n)
			continue;

		if(a[nx][ny] == '1' && !visited[nx][ny]){
			dfs(nx, ny);
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
				depth = 0; //초기화
				dfs(i, j);
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

