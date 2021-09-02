#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int, int>> v;

int main(){
	int n;
	cin>>n;
	int ans[n];

	for(int i=0; i<n; i++){
		int x;
		cin>>x;

		//값과 인덱스 pair로 저장
		v.push_back(make_pair(x, i));
	}

	//값을 기준으로 정렬
	sort(v.begin(), v.end());

	int idx = 0;
	for(int i=0; i<n; i++){
		//현재 값이 이전 값과 같은 경우
		if(i != 0 && v[i].first == v[i-1].first)
			idx--;

		ans[v[i].second] = idx++;
	}

	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";

    return 0;
}

