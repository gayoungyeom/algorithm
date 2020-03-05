/*
 * d[i][j]: //d[물건][남은 무게]
 */
#include <iostream>
using namespace std;

int v[101];
int w[101];
int d[101][100001];
int n, k;

int dp(int i, int j){
	if(i == 0) return 0;
	if(d[i][j] != 0) return d[i][j];
	d[i][j] = dp(i-1, j);
	if(j - w[i] >= 0) //max(i번째 물건 포함x, i번째 물건 포함o)
		d[i][j] = max(d[i][j], dp(i-1, j-w[i]) + v[i]);
	return d[i][j];
}

int main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>w[i]>>v[i];
	cout<<dp(n, k)<<'\n';
	return 0;
}

