#include <iostream>
#include <vector>
using namespace std;

int t[51][51]; //시간
bool v[51]; //방문 여부
int d[51]; //최소 비용
int INF = 1000000000;

//아직 방문하지 않은 노드 중에서 최소 비용 정점 반환
int get_small_idx(int n){
	int min = INF;
	int idx = 0;
	for(int i=1; i<=n; i++){
		if(!v[i] && d[i] < min){
			min = d[i];
			idx = i;
		}
	}
	return idx;
}

void dijkstra(int n, int start){
	v[start] = true; //시작점 방문 처리
	for(int i=1; i<=n; i++){ //시작점의 인접 정점 초기화
		d[i] = t[start][i];
	}
	for(int i=1; i<=n; i++){
		int cur = get_small_idx(n);
		v[cur] = true; //cur 방문 처리
		for(int i=1; i<=n; i++){ //cur의 인접 정점 탐색
			if(!v[i] && t[cur][i] + d[cur] < d[i])
				d[i] = t[cur][i] + d[cur];
		}
	}
}

int solution(int n, vector<vector<int>> road, int k) {
	for(int i=0; i<(int)road.size(); i++){
		int x = road[i][0];
		int y = road[i][1];
		int time = road[i][2];
		if(!t[x][y]) t[x][y] = t[y][x] = time;
		else t[x][y] = t[y][x] = min(t[x][y], time);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) continue;
			if(!t[i][j]) t[i][j] = INF;
		}
	}

	dijkstra(n, 1);

	int ans = 0;
	for(int i=1; i<=n; i++)
		if(d[i] <= k) ans++;
	return ans;
}
