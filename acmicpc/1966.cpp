#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);

	int T, n, m;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>n>>m;
		int impt;
		int pri[n];
		queue<pair<int, int>> q;
		for(int j=0; j<n; j++){
			cin>>impt;
			pri[j] = impt;
			q.push(make_pair(j, impt));
		}

		sort(pri, pri + n, cmp);

		int cnt = 0;
		for(int j=0; j<n; j++){
			while(1){
				if(q.front().second == pri[j]){
					cnt++;
					if(q.front().first == m){
						cout<<cnt<<'\n';
						j = n-1;
					}
					else{
						q.pop();
					}
					break;
				}
				else{
					q.push(q.front());
					q.pop();
				}
			}
		}
	}

	return 0;
}

