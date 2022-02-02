#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 200001; //이동가능한 범위는 20만!!
int dist[MAX];
int route[MAX]; //이동 경로

int main(){
	int n, k;
	cin>>n>>k;

	queue<int> q;
	q.push(n);
	dist[n] = 1;

	while(!q.empty()){
		int x = q.front();
		q.pop();

		//이동 가능한 위치
		if(x - 1 >= 0 && !dist[x-1]){
			q.push(x-1);
			dist[x-1] = dist[x] + 1;
			route[x-1] = x;
		}
		if(x + 1 < MAX && !dist[x+1]){
			q.push(x+1);
			dist[x+1] = dist[x] + 1;
			route[x+1] = x;
		}
		if(2 * x < MAX && !dist[2*x]){
			q.push(2*x);
			dist[2*x] = dist[x] + 1;
			route[2*x] = x;
		}
	}

	int cnt = dist[k] - 1;
	cout<<cnt<<'\n';

	stack<int> s;
	s.push(k);
	while(cnt--){
		int x = s.top();
		s.push(route[x]);
	}

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}

