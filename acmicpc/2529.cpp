//168ms 소요
#include <iostream>
#include <vector>
using namespace std;

int k;
vector<char> sign;
vector<int> v;
bool visited[10];
vector<string> ans;

void go(int idx){
	if((int)v.size() == k+1){
		bool flag = true;
		for(int i=0; i<k; i++){
			if(sign[i] == '<'){
				if(v[i] > v[i+1]){
					flag = false;
					break;
				}
			} else{ //'>'
				if(v[i] < v[i+1]){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			string s = "";
			for(int i=0; i<k+1; i++)
				s += to_string(v[i]);
			ans.push_back(s);
		}
		return;
	}
	for(int i=0; i<10; i++){
		if(!visited[i]){
			visited[i] = true;
			v.push_back(i);
			go(i+1);
			visited[i] = false;
			v.pop_back();
		}
	}
}

int main(){
	cin>>k;
	for(int i=0; i<k; i++){
		char c;
		cin>>c;
		sign.push_back(c);
	}
	go(0);
	cout<<ans[ans.size()-1]<<'\n';
	cout<<ans[0]<<'\n';
	return 0;
}
