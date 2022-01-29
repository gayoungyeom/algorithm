//그래프의 표현 방식 모두 사용해보기
#include <iostream>
#include <vector>
using namespace std;

bool arr[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

int main(){
	int n, m;
	cin>>n>>m;

	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		//간선리스트
		edges.push_back({a, b});
		edges.push_back({b, a});
		//인접행렬
		arr[a][b] = arr[b][a] = true;
		//인접리스트
		g[a].push_back(b);
		g[b].push_back(a);
	}

	m *= 2; //간선이 양방향이므로 2배
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			//A -> B
			int A = edges[i].first;
			int B = edges[i].second;

			//C -> D
			int C = edges[j].first;
			int D = edges[j].second;

			if(A == B || A == C || A == D || B == C || B == D || C == D) continue;

			//B -> C
			if(!arr[B][C]) continue;

			//D -> E
			for(int E: g[D]){
				if(A == E || B == E || C == E || D == E) continue;
				cout<<1<<'\n';
				return 0;
			}
		}
	}
	cout<<0<<'\n';
	return 0;
}
