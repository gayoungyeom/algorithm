#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

void dfs(int cur){
	if((int)v.size() == m){
		for(int i=0; i<m; i++)
			cout<<v[i]<<" ";
		cout<<'\n';
		return;
	}
	for(int i=1; i<=n; i++){
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>n>>m;
	dfs(0);
	return 0;
}
