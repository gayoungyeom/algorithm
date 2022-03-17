//입력이 많으면 빠른 입출력 사용하기!
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int a[2001];
int f[2001][2001]; //i부터 j까지 펠린드롬 체크

bool dp(int s, int e){
	if(s == e) return 1;
	if(e - s == 1){
		if(a[s] == a[e]) return 1;
		else return 0;
	}

	if(f[s][e] != -1) return f[s][e];

	if(a[s] != a[e]) return f[s][e] = 0;
	else return f[s][e] = dp(s+1, e-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];

	memset(f, -1, sizeof(f));

	cin>>m;
	while(m--){
		int s, e;
		cin>>s>>e;
		cout<<dp(s, e)<<'\n';
	}

	return 0;
}

