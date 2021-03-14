#include <string>
#include <vector>

using namespace std;

vector<int> v[201];
bool visited[201];

void dfs(int cur){
	visited[cur] = true;
	for(unsigned int i=0; i<v[cur].size(); i++){
		if(!visited[v[cur][i]]){
			dfs(v[cur][i]);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i < j && computers[i][j]){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
    
    for(int i=0; i<n; i++){
		if(!visited[i]){
			dfs(i);
			answer++;
		}
	}
    return answer;
}
