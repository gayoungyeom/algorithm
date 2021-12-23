#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//O(n^2) -> O(n)으로 줄이는 방법: 확인할 행과 열 인덱스를 넘겨서 바뀌는 부분만 다시 계산한다.
int check(vector<string> &box){
	int n = box.size();
	int ans = 1;

	for(int i=0; i<n; i++){
		//행 check
		int cnt = 1;
		for(int j=1; j<n; j++){
			if(box[i][j] == box[i][j-1]) cnt++;
			else cnt = 1;
			ans = max(ans, cnt);
		}

		//열 check
		cnt = 1;
		for(int j=1; j<n; j++){
			if(box[j][i] == box[j-1][i]) cnt++;
			else cnt = 1;
			ans = max(ans, cnt);
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<string> box(n);

	for(int i=0; i<n; i++)
		cin>>box[i];

	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//오른쪽
			if(j != n-1 && box[i][j] != box[i][j+1]){
				swap(box[i][j], box[i][j+1]);
				int tmp = check(box);
				ans = max(ans, tmp);
				swap(box[i][j], box[i][j+1]);
			}

			//아래쪽
			if(i != n-1 && box[i][j] != box[i+1][j]){
				swap(box[i][j], box[i+1][j]);
				int tmp = check(box);
				ans = max(ans, tmp);
				swap(box[i][j], box[i+1][j]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
