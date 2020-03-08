#include <iostream>
#include <queue>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n, k;
	cin>>n>>k;

	queue<int> q;
	queue<int> ans;
	for(int i=1; i<=n; i++)
		q.push(i);

	int cnt = n;
	while(cnt != 1){
		for(int i=0; i<k-1; i++){
			q.push(q.front());
			q.pop();
		}
		ans.push(q.front());
		q.pop();
		cnt--;
	}

	ans.push(q.front());
	cout<<'<';
	for(int i=0; i<n-1; i++){
		cout<<ans.front()<<", ";
		ans.pop();
	}
	cout<<ans.front()<<'>';

	return 0;
}
