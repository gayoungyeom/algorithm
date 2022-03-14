#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int x1, y1, x2, y2; //c 좌표
char a[101][101];
int dist[101][101];
queue<pair<int, int>> q;

void bfs(){
	q.push(make_pair(x1, y1));
	dist[x1][y1] = 0;

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=x; i>=0; i--){//상
			if(a[i][y] == '*') break;
			if(dist[i][y] == -1){
				dist[i][y] = dist[x][y] + 1;
				q.push(make_pair(i, y));
			}
		}
		for(int i=x; i<h; i++){ //하
			if(a[i][y] == '*') break;
			if(dist[i][y] == -1){
				dist[i][y] = dist[x][y] + 1;
				q.push(make_pair(i, y));
			}
		}
		for(int i=y; i>=0; i--){//좌
			if(a[x][i] == '*') break;
			if(dist[x][i] == -1){
				dist[x][i] = dist[x][y] + 1;
				q.push(make_pair(x, i));
			}
		}
		for(int i=y; i<w; i++){//우
			if(a[x][i] == '*') break;
			if(dist[x][i] == -1){
				dist[x][i] = dist[x][y] + 1;
				q.push(make_pair(x, i));
			}
		}
	}
}

int main(){
	cin>>w>>h;
	x1 = y1 = x2 = y2 = -1; //값이 0일수도 있으니까 -1로 초기화 해주기
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin>>a[i][j];
			if(a[i][j] == 'C'){
				if(x1 == -1){
					x1 = i;
					y1 = j;
				} else{
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	memset(dist, -1, sizeof(dist));

	bfs();

	cout<<dist[x2][y2]-1<<'\n';

	return 0;
}

