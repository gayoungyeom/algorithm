#include <iostream>
using namespace std;

int a[102][102]; //범위가 중요함
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main(){
	int n, m;
	cin>>n>>m;

	//i,j가 0 또는 n,m인 경우를 겉넓이에 더해 주어야 하므로 범위 아래처럼 지정
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>a[i][j];

	int ans = n*m*2; //윗면 + 밑면

	//모든 칸에 대해 상하좌우 높이 차 확인
	for(int x=1; x<=n; x++){
		for(int y=1; y<=m; y++){
			for(int k=0; k<4; k++){
				int nx = x + dx[k];
				int ny = y + dy[k];
				int diff = a[x][y] - a[nx][ny];
				if(diff > 0){
					ans += diff;
				}
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}

