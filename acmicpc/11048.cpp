#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	int a[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>a[i][j];

	int f[n][m];
	for(int r=0; r<n; r++){
		for(int c=0; c<m; c++){
			if(r == 0 && c == 0)
				f[r][c] = a[r][c];
			else if(r == 0)
				f[r][c] = f[r][c-1] + a[r][c];
			else if(c == 0)
				f[r][c] = f[r-1][c] + a[r][c];
			else
				f[r][c] = max({f[r][c-1], f[r-1][c], f[r-1][c-1]}) + a[r][c];
		}
	}

	cout<<f[n-1][m-1]<<'\n';

	return 0;
}

