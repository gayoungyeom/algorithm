#include <iostream>
using namespace std;

int main(){
	int n, m, k;

	cin>>n>>m;
	int fir[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m ;j++){
			cin>>fir[i][j];
		}
	}

	cin>>m>>k;
	int sec[m][k];
	for(int i=0; i<m; i++){
		for(int j=0; j<k ;j++){
			cin>>sec[i][j];
		}
	}

	int ans[n][k];
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			ans[i][j] = 0;
			for(int l=0; l<m; l++){
				ans[i][j] += (fir[i][l] * sec[l][j]);
			}
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

