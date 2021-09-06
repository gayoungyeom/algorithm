#include <iostream>
using namespace std;

int n, cnt;
int x[16];

//현재 자리에 Queen이 위치할 수 있는지 판단
bool isPlaceAt(int row, int col){
	for(int i=0; i<row; i++){
		//같은 열에 Queen 존재 확인
		if(x[i] == col) return false;
		//왼쪽 대각선에 Queen 존재 확인
		if(x[i] == col - (row - i)) return false;
		//오른쪽 대각선에 Queen 존재 확인
		if(x[i] == col + (row - i)) return false;
	}
	return true;
}

void backtrack(int row){
	if(row == n) cnt++;

	for(int col=0; col<n; col++){
		if(isPlaceAt(row, col)){
			x[row] = col;
			backtrack(row + 1);
		}
	}
}

int main(){
	cin>>n;
	backtrack(0);
	cout<<cnt<<endl;
	return 0;
}

