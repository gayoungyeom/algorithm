#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;
bool visited[15];
int L, C;
char arr[15];

void backtrack(int curIdx){
	if((int)v.size() == L){
		int m = 0; //모음 개수
		int j = 0; //자음 개수
		for(int i=0; i<L; i++){
			char cur = v[i];
			if(cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u') m++;
			else j++;
		}
		if(m >= 1 && j >= 2){
			for(int i=0; i<L; i++)
				cout<<v[i];
			cout<<'\n';
		}
		return;
	}
	for(int i=curIdx; i<C; i++){
		if(!visited[i]){
			visited[i] = true;
			v.push_back(arr[i]);
			backtrack(i);
			visited[i] = false;
			v.pop_back();
		}
	}

}

int main(){
	cin>>L>>C;
	for(int i=0; i<C; i++){
		cin>>arr[i];
	}
	sort(arr, arr + C);
	backtrack(0);
	return 0;
}

