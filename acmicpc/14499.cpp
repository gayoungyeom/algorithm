#include <iostream>
using namespace std;

int dice[4][3]; //top: dice[1]][1], bottom: dice[3][1]

//동: 1, 서: 2, 북: 3, 남: 4
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main(){
	int n, m, x, y, k;
	cin>>n>>m>>x>>y>>k;

	int a[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	for(int i=0; i<k; i++){
		int mv;
		cin>>mv;

		int nx = x + dx[mv-1];
		int ny = y + dy[mv-1];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		int tmp[4][3];
		for(int i=0; i<4; i++)
			for(int j=0; j<3; j++)
				tmp[i][j] = dice[i][j];

		if(mv == 1){
			tmp[1][0] = dice[3][1];
			tmp[1][1] = dice[1][0];
			tmp[1][2] = dice[1][1];
			tmp[3][1] = dice[1][2];
		} else if(mv == 2){
			tmp[1][0] = dice[1][1];
			tmp[1][1] = dice[1][2];
			tmp[1][2] = dice[3][1];
			tmp[3][1] = dice[1][0];
		} else if(mv == 3){
			tmp[0][1] = dice[1][1];
			tmp[1][1] = dice[2][1];
			tmp[2][1] = dice[3][1];
			tmp[3][1] = dice[0][1];
		} else if(mv == 4){
			tmp[0][1] = dice[3][1];
			tmp[1][1] = dice[0][1];
			tmp[2][1] = dice[1][1];
			tmp[3][1] = dice[2][1];
		}

		for(int i=0; i<4; i++)
				for(int j=0; j<3; j++)
					dice[i][j] = tmp[i][j];

		x = nx;
		y = ny;

		if(a[nx][ny] == 0){
			a[nx][ny] = dice[3][1];
		} else{
			dice[3][1] = a[nx][ny];
			a[nx][ny] = 0;
		}

		cout<<dice[1][1]<<'\n';
	}

	return 0;
}

