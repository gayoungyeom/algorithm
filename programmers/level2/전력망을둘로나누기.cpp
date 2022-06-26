#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<int> v[101];
bool visited[101];

int ans = 101;
int cnt = 0;

void dfs(int cur, int n, vector<vector<int>>& wires){
    visited[cur] = true;
    for(int i=0; i<v[cur].size(); i++){
        if(!visited[v[cur][i]]){
            dfs(v[cur][i], n, wires);
        }
    }
    cnt++;
}

int solution(int n, vector<vector<int>> wires) {
    for(int i=0; i<wires.size(); i++){
        //변수들 초기화
        for(int j=1; j<=n; j++) v[j].clear();
        memset(visited, false, n+1);

        int cut = i;
        for(int j=0; j<wires.size(); j++){
            if(cut == j) continue; //전선 끊기
            int v1 = wires[j][0];
            int v2 = wires[j][1];
            v[v1].push_back(v2);
            v[v2].push_back(v1);
        }
        
        //두 송전탑의 개수 카운팅
        vector<int> tmp;
        for(int j=1; j<=n; j++){
            if(!visited[j]){
                cnt = 0;
                dfs(j, n, wires);
                tmp.push_back(cnt);
            }
        }
        
        //두 송전탑 개수 차이 계산
        int diff = tmp[0] - tmp[1];
        if(diff < 0) diff = -diff;
        ans = min(ans, diff);
    }
    
    return ans;
}
