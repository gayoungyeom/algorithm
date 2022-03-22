#include <iostream>
using namespace std;

string s1, s2;
int f[4001][4001];
int ans;

void dp(int n, int m){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i] == s2[j]) {
				if(s1[i-1] == s2[j-1])
					f[i][j] = f[i-1][j-1] + 1;
				else
					f[i][j] = 1;
			}
			else f[i][j] = max(f[i-1][j], f[i][j-1]);
			ans = max(ans, f[i][j]);
		}
	}
}

int main(){
	cin>>s1>>s2;
	int n = s1.length();
	int m = s2.length();
	s1 = '0' + s1;
	s2 = '1' + s2;
	dp(n, m);
	cout<<ans<<'\n';
	return 0;
}

