#include <iostream>
using namespace std;

int paper[129][129];
int white, blue;

//paper[i][j]에서 n의 길이만큼 탐색
void dc(int x, int y, int n){
	if(n == 1){ //base case
		if(paper[x][y]) blue++;
		else white++;
		return;
	}
	else{ //recursive
		//모두 같은 색으로 칠해져 있는지 판단
		int cur = paper[x][y];
		bool one = true;
		for(int i=x; i<x+n; i++){
			for(int j=y; j<y+n; j++){
				if(cur != paper[i][j]){
					one = false;
					break;
				}
			}
			if(!one) break;
		}

		if(one){ //모두 같은 색으로 칠해져 있을 때
			if(cur) blue++;
			else white++;
		}
		else{ //모두 같은 색으로 칠해져 있지 않을 때
			dc(x, y, n/2);
			dc(x, y + n/2, n/2);
			dc(x + n/2, y, n/2);
			dc(x + n/2, y + n/2, n/2);
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>paper[i][j];
		}
	}

	dc(0, 0, n);

	cout<<white<<'\n';
	cout<<blue<<'\n';

	return 0;
}

