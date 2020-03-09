#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n, m;
	cin>>n>>m;

	int arr[m];
	for(int i=0; i<m; i++)
		cin>>arr[i];

	deque<int> dq;
	for(int i=1; i<=n; i++)
		dq.push_back(i);

	int cnt = 0;
	for(int i=0; i<m; i++){
		int idx;
		for(int j=0; j<(int)dq.size(); j++){
			if(arr[i] == dq[j]){
				idx = j;
				break;
			}
		}

		while(1){
			if(arr[i] == dq.front()){ //1번 연산
				dq.pop_front();
				break;
			}

			int d2 = idx; //front와 거리
			int d3 = dq.size() - 1 - idx; //back과 거리
			if(d2 <= d3){ //2번 연산
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			else{ //3번 연산
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
	}

	cout<<cnt;

	return 0;
}

