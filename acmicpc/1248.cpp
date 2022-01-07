#include <iostream>
#include <vector>
using namespace std;

int n;
char arr[10][10];
vector<int> v;
bool flag = false;

bool check(int idx){// idx번째에 들어가는 숫자가 조건을 만족하는지 check
	int sum = 0;
	for(int i=idx; i>=0; i--){
		sum += v[i];
		if(sum <= 0 && arr[i][idx] == '+') return false;
		if(sum != 0 && arr[i][idx] == '0') return false;
		if(sum >= 0 && arr[i][idx] == '-') return false;
	}
	return true;
}

void backtrack(int idx){ //idx: 위치
	if(flag) return;
	if(idx == n){
		for(int i=0; i<n; i++)
			cout<<v[i]<<" ";
		cout<<'\n';
		flag = true;
		return;
	}
	for(int i=-10; i<=10; i++){
		v.push_back(i);
		if(check(idx))
			backtrack(idx + 1);
		v.pop_back();
	}
}

int main(){
	cin>>n;
	string s;
	cin>>s;

	int x = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i <= j) arr[i][j] = s[x++];

	backtrack(0);
	return 0;
}

