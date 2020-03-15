#include <iostream>
#include <queue>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n;
	cin>>n;

	queue<int> q;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		if(s == "push"){
			int x;
			cin>>x;
			q.push(x);
		} else if(s == "pop"){
			if(q.empty()) cout<<-1<<'\n';
			else{
				cout<<q.front()<<'\n';
				q.pop();
			}
		} else if(s == "size"){
			cout<<q.size()<<'\n';
		} else if(s == "empty"){
			cout<<q.empty()<<'\n';
		} else if(s == "front"){
			if(q.empty()) cout<<-1<<'\n';
			else cout<<q.front()<<'\n';
		} else{ //s == "back"
			if(q.empty()) cout<<-1<<'\n';
			else cout<<q.back()<<'\n';
		}
	}
	return 0;
}
