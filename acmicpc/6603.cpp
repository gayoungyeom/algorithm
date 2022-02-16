//N과 M(2)와 유사
#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> v;
bool visited[50];

void backtrack(int index, vector<int> &s){
	if(v.size() == 6){
		for(int i=0; i<6; i++)
			cout<<s[v[i]]<<" ";
		cout<<'\n';
		return;
	}

	for(int i=index; i<k; i++){
		if(!visited[i]){
			visited[i] = true;
			v.push_back(i);

			backtrack(i + 1, s);

			visited[i] = false;
			v.pop_back();
		}
	}
}


int main(){
	while(cin>>k, k){
		vector<int> s(k);
		for(int i=0; i<k; i++){
			cin>>s[i];
		}

		backtrack(0, s);
		cout<<'\n';

		for(int i=0; i<6; i++){
			v[i] = 0;
			visited[i] = false;
		}
	}
	return 0;
}

