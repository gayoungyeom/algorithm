#include <iostream>
#include <vector>
using namespace std;

class stack{
	vector<int> v;
public:
	void push(int x){
		v.push_back(x);
	}
	int pop(){
		if(empty()) return -1;
		int tmp = *(v.end()-1);
		v.pop_back();
		return tmp;
	}
	int size(){
		return v.size();
	}
	int empty(){
		return v.empty();
	}
	int top(){
		if(empty()) return -1;
		return *(v.end()-1);
	}
};

int main(){
	int n;
	cin>>n;

	stack s;
	string cmd;
	for(int i=0; i<n; i++){
		cin>>cmd;
		if(cmd == "push"){
			int x;
			cin>>x;
			s.push(x);
		}
		else if(cmd == "pop"){
			cout<<s.pop()<<'\n';
		}
		else if(cmd == "size"){
			cout<<s.size()<<'\n';
		}
		else if(cmd == "empty"){
			cout<<s.empty()<<'\n';
		}
		else{ //cmd == "top"
			cout<<s.top()<<'\n';
		}
	}

	return 0;
}

