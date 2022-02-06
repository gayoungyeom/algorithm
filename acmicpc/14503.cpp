#include <iostream>
using namespace std;

//0, 1, 2, 3 각각이 이동하는 방향
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	int n, m;
	cin>>n>>m;

	int x, y, d;
	cin>>x>>y>>d;

	int a[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

    int ans = 0;

    while (true) {
    	//1. 현재 위치 청소
        if (a[x][y] == 0) {
            a[x][y] = 2;
            ans++;
        }

        //2-3, 2-4. 네 방향 모두 청소가 되어있거나 벽인 경우
        if(a[x+1][y] != 0 && a[x-1][y] != 0 && a[x][y-1] != 0 && a[x][y+1] != 0){
			//2-4. 후진 불가한 경우 종료
            if (a[x-dx[d]][y-dy[d]] == 1)
                break;

			//2-3. 한 칸 후진 후 2번으로
			x -= dx[d];
			y -= dy[d];
        } else { // 2-1, 2-2
            d = (d + 3) % 4;
			//2-1. 회전 후 1번으로
            if(a[x+dx[d]][y+dy[d]] == 0){
                x += dx[d];
                y += dy[d];
            }
            //2-2. 그냥 1번으로
        }
    }

    cout << ans << '\n';

    return 0;
}

