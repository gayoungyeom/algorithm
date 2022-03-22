#include <iostream>
#include <cstring>
using namespace std;

int a[1001][1001];
int tmp[1001][1001];
pair<int, int> air = {0, 0};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
	int r, c, t;
	cin>>r>>c>>t;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>a[i][j];
			if(a[i][j] == -1){
				if(air.first == 0) air.first = i;
				else air.second = i;
			}
		}
	}

	while(t--){
		//1. 미세먼지 확산
		memset(tmp, 0, sizeof(tmp));
		for(int x=0; x<r; x++){
			for(int y=0; y<c; y++){
				if(a[x][y] != 0 && a[x][y] != -1){
					int cnt = 0;
					int dust = a[x][y] / 5;
					for(int k=0; k<4; k++){
						int nx = x + dx[k];
						int ny = y + dy[k];

						if(nx < 0 || nx >= r || ny < 0 || ny >= c)
							continue;

						if(a[nx][ny] != -1){
							tmp[nx][ny] += dust;
							cnt++;
						}
					}
					if(cnt > 0)
						tmp[x][y] += (a[x][y] - (dust * cnt));
					else
						tmp[x][y] += a[x][y];
				}
			}
		}
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(a[i][j] != -1)
					a[i][j] = tmp[i][j];
			}
		}

		//2. 공기청정기 작동
		//위쪽
		int bound = air.first;
		for(int i=bound-1; i>0; i--)
			a[i][0] = a[i-1][0];
		for(int i=0; i<c-1; i++)
			a[0][i] = a[0][i+1];
		for(int i=0; i<bound; i++)
			a[i][c-1] = a[i+1][c-1];
		for(int i=c-1; i>1; i--)
			a[bound][i] = a[bound][i-1];
		a[bound][1] = 0;

		//아래쪽
		bound = air.second;
		for(int i=bound+1; i<r-1; i++)
			a[i][0] = a[i+1][0];
		for(int i=0; i<c-1; i++)
			a[r-1][i] = a[r-1][i+1];
		for(int i=r-1; i>bound; i--)
			a[i][c-1] = a[i-1][c-1];
		for(int i=c-1; i>1; i--)
			a[bound][i] = a[bound][i-1];
		a[bound][1] = 0;

	}

	int ans = 0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(a[i][j] != -1)
				ans += a[i][j];
		}
	}
	cout<<ans<<'\n';

	return 0;
}

