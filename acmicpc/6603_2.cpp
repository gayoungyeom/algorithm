//재귀 버전
#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> v;

void go(vector<int> &s, int index, int cnt){
	//1. 종료 조건
	if(cnt == 6){
		for(int i=0; i<6; i++)
			cout<<s[v[i]]<<" ";
		cout<<'\n';
		return;
	}

	//2. 불가능한 경우
	if(index == k) return;

	//3. 다음 경우 호출
	//3-1. 현재 index 선택하는 경우를 먼저 호출해야 함
	v.push_back(index);
	go(s, index+1, cnt+1);
	v.pop_back();

	//3-2. 현재 index 선택하지 않는 경우
	go(s, index+1, cnt);
}


int main(){
	while(cin>>k, k){
		vector<int> s(k);

		for(int i=0; i<k; i++)
			cin>>s[i];

		go(s, 0, 0);

		cout<<'\n';
	}
	return 0;
}

