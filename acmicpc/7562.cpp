#include <iostream>
#include <queue>
#include <cstring> //memset 헤더
using namespace std;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
	int t;
	cin>>t;

	while(t--){
		int l;
		cin>>l;
		int a[l][l];
		memset(a, -1, sizeof(a));

		int cx, cy, mx, my;
		cin>>cx>>cy;
		cin>>mx>>my;

		queue<pair<int, int>> q;
		q.push(make_pair(cx, cy));
		a[cx][cy] = 0; //cx=mx && cy=my인 경우 0이므로

		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for(int i=0; i<8; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];

				if(nx < 0 || nx >= l || ny < 0 || ny >= l)
					continue;

				if(a[nx][ny] == -1){ //방문하지 않은 경우
					q.push(make_pair(nx, ny));
					a[nx][ny] = a[x][y] + 1;
				}
			}
		}
		cout<<a[mx][my]<<'\n';
	}

	return 0;
}

