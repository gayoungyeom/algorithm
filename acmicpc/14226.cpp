#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1001; //이론상 가능한 범위는 2001
int dist[MAX][MAX];

int main(){
	int n;
	cin>>n;
	memset(dist, -1, sizeof(dist));

	queue<pair<int, int>> q; //(s, c): 화면, 클립보드
	q.push(make_pair(1, 0));
	dist[1][0] = 0;

	while(!q.empty()){
		int s = q.front().first;
		int c = q.front().second;
		q.pop();

		if(dist[s][s] == -1){ //1번 연산: 클립보드 저장
			q.push(make_pair(s, s));
			dist[s][s] = dist[s][c] + 1;
		}
		if(s + c <= n && dist[s+c][c] == -1){ //2번 연산: 붙여넣기
			q.push(make_pair(s+c, c));
			dist[s+c][c] = dist[s][c] + 1;
		}
		if(s - 1 >= 0 && dist[s-1][c] == -1){ //3번 연산: 하나 삭제하기
			q.push(make_pair(s-1, c));
			dist[s-1][c] = dist[s][c] + 1;
		}
	}

	int ans = MAX;
	for(int i=0; i<=n; i++){
		if(dist[n][i] != -1)
			ans = min(ans, dist[n][i]);
	}
	cout<<ans<<'\n';

	return 0;
}

