#include <iostream>
using namespace std;

char qt[65][65];

void dc(int x, int y, int n){
	if(n == 1){
		cout<<qt[x][y];
	}
	else{
		int cur = qt[x][y] - '0';
		bool flag = true;
		for(int i=x; i<x+n; i++){
			for(int j=y; j<y+n; j++){
				if(cur != (qt[i][j] - '0')){
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}

		if(flag){
			cout<<cur;
		}
		else{
			int mid = n / 2;
			cout<<'(';
			dc(x, y, mid);
			dc(x, y + mid, mid);
			dc(x + mid, y, mid);
			dc(x + mid, y + mid, mid);
			cout<<')';
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>qt[i][j];
		}
	}

	dc(0, 0, n);

	return 0;
}

