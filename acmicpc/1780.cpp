#include <iostream>
using namespace std;

int paper[2188][2188];
int moneCnt, zeroCnt, oneCnt;

void dc(int x, int y, int n){
	if(n == 1){
		if(paper[x][y] == -1) moneCnt++;
		else if(paper[x][y] == 0) zeroCnt++;
		else oneCnt++;
	}
	else{
		int cur = paper[x][y];
		bool flag = true;
		for(int i=x; i<x+n; i++){
			for(int j=y; j<y+n; j++){
				if(cur != paper[i][j]){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}

		if(flag){
			if(cur == -1) moneCnt++;
			else if(cur == 0) zeroCnt++;
			else oneCnt++;
		}
		else{
			int div = n / 3;
			dc(x, y, div);
			dc(x, y + div, div);
			dc(x, y + 2*div, div);
			dc(x + div, y, div);
			dc(x + div, y + div, div);
			dc(x + div, y + 2*div, div);
			dc(x + 2*div, y, div);
			dc(x + 2*div, y + div, div);
			dc(x + 2*div, y + 2*div, div);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>paper[i][j];
		}
	}

	dc(0, 0, n);

	cout<<moneCnt<<'\n';
	cout<<zeroCnt<<'\n';
	cout<<oneCnt<<'\n';

	return 0;
}

