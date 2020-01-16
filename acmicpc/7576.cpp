#include <iostream>
#include <queue>
using namespace std;

int main(){
	queue<pair<int, int>> q;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int M, N;
	int answer = 0;
	bool flag = false;

	cin>>M>>N; //M가로, N세로
	int box[N][M];
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>box[i][j];
			if(box[i][j] == 1) q.push({i,j});
		}
	}

	while(!q.empty()){//더이상 탐색할 노드 없을 때까지
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || ny < 0 || nx >= N || ny >= M) //경계 넘어가는 값 제어
				continue;

			if(box[nx][ny] == 0){ //다음에 탐색하는 토마토가 덜 익은 경우
				q.push({nx, ny});
				box[nx][ny] = box[x][y] + 1; //count
			}
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(box[i][j] == 0) //방문체크 -> 0: 방문하지 않았다는 뜻
				flag = true;
			answer = max(answer, box[i][j]);
		}
	}

	if(flag)
		cout<<-1<<endl;
	else
		cout<<answer - 1<<endl;

	return 0;
}
