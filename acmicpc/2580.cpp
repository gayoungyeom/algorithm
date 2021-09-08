#include <iostream>
#include <vector>
using namespace std;

int sd[9][9];
vector<pair<int, int>> v;
bool flag = false;

bool isSetNum(int row, int col){
	int cur = sd[row][col];

	//가로
	for(int i=0; i<9; i++){
		if(i == col) continue;
		if(cur == sd[row][i]) return false;
	}

	//세로
	for(int i=0; i<9; i++){
		if(i == row) continue;
		if(cur == sd[i][col]) return false;
	}

	//3x3 정사각형
	int r = row / 3;
	int c = col / 3;

	for(int i=r*3; i<r*3 + 3; i++){
		for(int j=c*3; j<c*3 + 3; j++){
			if(i == row && j == col) continue;
			if(cur == sd[i][j])	return false;
		}
	}

	return true;
}

void backtrack(int cur){
	if((int)v.size() == cur){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++)
				cout<<sd[i][j]<<" ";
			cout<<endl;
		}
		flag = true;
		return;
	}

	for(int i=1; i<=9; i++){
		sd[v[cur].first][v[cur].second] = i; //숫자 넣기
		if(isSetNum(v[cur].first, v[cur].second)){ //현자 자리에서 위 숫자의 유효성 판단
			backtrack(cur + 1);
			if(flag) return; //스도쿠가 완성된 경우 종료 -> 안해주면 무한루프 돌 수도 있음
		}
		sd[v[cur].first][v[cur].second] = 0; //유효한 숫자가 아닌 경우 값 비워주기
	}
}

int main(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>sd[i][j];
			if(!sd[i][j])
				v.push_back(make_pair(i, j));
		}
	}

	backtrack(0);

	return 0;
}

