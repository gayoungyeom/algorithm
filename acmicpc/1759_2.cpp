#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> v;

bool check(string password){
	int m = 0; //모음 개수
	int j = 0; //자음 개수
	for(char cur : password){
		if(cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u') m++;
		else j++;
	}
	return m >= 1 && j >= 2;
}

void go(int curIdx, string password){
	if((int)password.length() == L){
		if(check(password))
			cout<<password<<'\n';
		return;
	}
	if(curIdx >= (int)v.size()) return;
	go(curIdx+1, password+v[curIdx]); //curIdx의 알파벳 사용
	go(curIdx+1, password);	 //curIdx의 알파벳 사용X
}

int main(){
	cin>>L>>C;
	for(int i=0; i<C; i++){
		char c;
		cin>>c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	go(0, "");
	return 0;
}

