#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200001;
int dist[MAX];

int main(){
	int n, k;
	cin>>n>>k;

	queue<int> q; //현재 큐
	queue<int> nq; //다음 큐
	q.push(n);
	dist[n] = 1;

	while(!q.empty()){
		int x = q.front();
		q.pop();

		if(2 * x < MAX && !dist[2*x]){ //2*x가 가장 앞에 와야 한다.
			q.push(2*x);
			dist[2*x] = dist[x];
		}
		if(x - 1 >= 0 && !dist[x-1]){
			nq.push(x-1);
			dist[x-1] = dist[x] + 1;
		}
		if(x + 1 < MAX && !dist[x+1]){
			nq.push(x+1);
			dist[x+1] = dist[x] + 1;
		}

		if(q.empty()){
			q = nq;
			nq = queue<int>();
		}
	}

	cout<<dist[k] - 1<<'\n';

	return 0;
}

