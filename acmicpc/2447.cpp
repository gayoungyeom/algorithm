#include <iostream>
using namespace std;

char arr[7000][7000];

void star(int x, int y, int n){
	if(n == 1){
		arr[x][y] = '*';
		return;
	}
	else{
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(i == 1 && j == 1) continue;
				star(x+(j*(n/3)), y+(i*(n/3)), n/3);
			}
		}
	}
}

int main(){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr[i][j] = ' ';
		}
	}

	star(0, 0, n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<arr[i][j];
		}
		cout<<'\n';
	}

	return 0;
}
