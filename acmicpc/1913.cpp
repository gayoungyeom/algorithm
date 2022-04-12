#include <iostream>
using namespace std;

int n, m, x, y;
int num = 1;
int a[1001][1001];

int dx[] = {-1, 0, 1, 0, -1};
int dy[] = {0, 1, 0, -1, 0};

void next_idx(int &x, int &y, int i){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(nx < 1 || nx > n || ny < 1 || ny > n) return;
	a[nx][ny] = num++;
	x = nx;
	y = ny;
}

int main(){
	cin>>n>>m;
	x = y = (n+1)/2;
	a[x][y] = num++;

	int g = 2;
	while(num < n*n){
		for(int i=0; i<5; i++){
			if(i == 0){
				next_idx(x, y, i);
			} else if(i == 1){
				for(int j=1; j<g; j++){
					next_idx(x, y, i);
				}
			} else{
				for(int j=1; j<=g; j++){
					next_idx(x, y, i);
				}
			}
		}
		g += 2;
	}

	int ax, ay;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout<<a[i][j]<<" ";
			if(a[i][j] == m){
				ax = i;
				ay = j;
			}
		}
		cout<<'\n';
	}
	cout<<ax<<" "<<ay<<'\n';

	return 0;
}
`
