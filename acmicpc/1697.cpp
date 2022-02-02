#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200001; //이동가능한 범위는 20만!!
int dist[MAX];

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
		}
		if(x + 1 < MAX && !dist[x+1]){
			q.push(x+1);
			dist[x+1] = dist[x] + 1;
		}
		if(2 * x < MAX && !dist[2*x]){
			q.push(2*x);
			dist[2*x] = dist[x] + 1;
		}
	}

	cout<<dist[k] - 1<<'\n';

	return 0;
}

