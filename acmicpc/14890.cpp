#include <iostream>
#include <vector>
using namespace std;

//각 행과 열을 독립적인 1차원으로 보고 체크
bool go(vector<int> &a, int l){
	int n = a.size();
	vector<bool> c(n, false); //경사로 놓았는지 여부

	for(int i=1; i<n; i++){
		if(a[i-1] != a[i]){
			int h = a[i] - a[i-1]; //높이
			if(h == 1){ //왼쪽에 경사로 놓을 수 있는지 확인
				for(int j=1; j<=l; j++){ //j개의 칸 확인
					if(i-j < 0) return false; //현재 위치에서 왼쪽으로 j칸 떨어진 곳이 지도의 범위 벗어난 경우
					if(a[i-1] != a[i-j]) return false; //높이가 다른 것이 있거나 L개가 연속되지 않은 경우
					if(c[i-j]) return false; //이미 경사로 놓은 경우
					c[i-j] = true;
				}
			} else if(h == -1){ //오른쪽에 경사로 놓을 수 있는지 확인
				for(int j=0; j<l; j++){
					if(i+j >= n) return false; //현재 위치에서 왼쪽으로 j칸 떨어진 곳이 지도의 범위 벗어난 경우
					if(a[i] != a[i+j]) return false; //높이가 다른 것이 있거나 L개가 연속되지 않은 경우
					if(c[i+j]) return false; //이미 경사로 놓은 경우
					c[i+j] = true;
				}
			} else{
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n, l;
	cin>>n>>l;

	vector<vector<int>> a(n, vector<int>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];

	int ans = 0;
	//행
	for(int i=0; i<n; i++){
		vector<int> d;
		for(int j=0; j<n; j++)
			d.push_back(a[i][j]);
		if(go(d, l)) ans++;
	}
	//열
	for(int j=0; j<n; j++){
		vector<int> d;
		for(int i=0; i<n; i++)
			d.push_back(a[i][j]);
		if(go(d, l)) ans++;
	}

	cout<<ans<<'\n';

	return 0;
}

