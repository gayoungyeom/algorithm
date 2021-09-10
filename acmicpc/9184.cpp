#include <iostream>
using namespace std;

int w[21][21][21];

int dp(int a, int b, int c){
	w[0][0][0] = 1;
	for(int i=0; i<=20; i++){
		for(int j=0; j<=20; j++){
			w[0][i][j] = 1;
			w[i][0][j] = 1;
			w[i][j][0] = 1;
		}
	}

	for(int i=1; i<=20; i++){
		for(int j=1; j<=20; j++){
			for(int k=1; k<=20; k++){
				if(i < j && j < k)
					w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
				else
					w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
			}
		}
	}

	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if(a > 20 || b > 20 || c > 20) return w[20][20][20];
	return w[a][b][c];
}

int main(){
	int a, b, c;
	int ans;

	while(1){
		cin>>a>>b>>c;
		if(a == -1 && b == -1 && c == -1) break;
		ans = dp(a, b, c);
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<ans<<endl;
	}

	return 0;
}

