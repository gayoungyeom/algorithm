#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> t[51]; //(인접 정점, 비용)
int d[51]; //최소 비용
int INF = 1000000000;

void dijkstra(int n, int start){
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({start, 0});

	while(!pq.empty()){
		int cur = pq.top().first; //최소 비용 정점 반환(자동으로 이루어짐)
		int dist = -pq.top().second; //최소 힙 이용하기 위해 음수화
		pq.pop();

		if(d[cur] < dist) continue; //최소 비용이 아닌 경우 스킵
		for(int i=0; i<(int)t[cur].size(); i++){ //cur의 인접 정점 탐색
			int next = t[cur][i].first;
			int nextdist = dist + t[cur][i].second;
			if(nextdist < d[next]){
				d[next] = nextdist;
				pq.push({next, -nextdist});
			}
		}
	}
}

int solution(int n, vector<vector<int>> road, int k) {
	for(int i=0; i<(int)road.size(); i++){
		int x = road[i][0];
		int y = road[i][1];
		int time = road[i][2];
		t[x].push_back({y, time});
		t[y].push_back({x, time});
	}
	for(int i=1; i<=n; i++)	d[i] = INF;

	dijkstra(n, 1);

	int ans = 0;
	for(int i=1; i<=n; i++)
		if(d[i] <= k) ans++;
	return ans;
}
