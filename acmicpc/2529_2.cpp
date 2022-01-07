//4ms 소요
#include <iostream>
#include <vector>
using namespace std;

int k;
vector<char> ops;
bool visited[10];
vector<string> ans;

bool ok(char x, char y, char op){
	if(op == '<'){
		if(x > y) return false;
	} else{ //'>'
		if(x < y) return false;
	}
	return true;
}

void go(int idx, string num){ //idx: 위치, num: 지금까지 만들어진 수
	if(idx == k+1){
		ans.push_back(num);
		return;
	}
	for(int i=0; i<10; i++){
		if(!visited[i]){
			if(idx == 0 || ok(num[idx-1], i+'0', ops[idx-1])){
				visited[i] = true;
				go(idx + 1, num + to_string(i));
				visited[i] = false;
			}
		}
	}
}

int main(){
	cin>>k;
	for(int i=0; i<k; i++){
		char c;
		cin>>c;
		ops.push_back(c);
	}
	go(0, "");
	cout<<ans[ans.size()-1]<<'\n';
	cout<<ans[0]<<'\n';
	return 0;
}

