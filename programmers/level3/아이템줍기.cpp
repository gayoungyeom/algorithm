#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int a[102][102]; //2배 하는 것 고려한 크기
int dist[102][102]; ///2배 하는 것 고려한 크기
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int n = rectangle.size();
    
    //값을 모두 2배하기 (bfs시 겹치는 부분 제거 위함)
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            rectangle[i][j] *= 2;
        }
    }
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for(int i=0; i<n; i++){
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3]; 
        
        //사각형 부분 모두 1로 설정
        for(int x=x1; x<=x2; x++){
            for(int y=y1; y<=y2; y++){
                a[x][y] = 1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3]; 
        
        // 테두리 제외 0으로 설정
        for(int x=x1+1; x<x2; x++){
            for(int y=y1+1; y<y2; y++){
                a[x][y] = 0;
            }
        }
    }
   
    memset(dist, -1, sizeof(dist));
    
    //bfs
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
    
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0) continue;
            
            if(a[nx][ny] && dist[nx][ny] == -1){
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    return dist[itemX][itemY] / 2;
}
