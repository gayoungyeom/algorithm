#include <iostream>
#include <deque>
using namespace std;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);

	int T, n;
	string p, arr;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>p>>n>>arr;

		deque<int> dq;
		string num;
		for(int j=0; j<(int)arr.size(); j++){
			if(arr[j] == '['){
				continue;
			}
			else if(isdigit(arr[j])){
				num += arr[j];
			}
			else if(arr[j] == ',' || arr[j] == ']'){
				if(!num.empty()){
					dq.push_back(stoi(num));
					num.clear();
				}
			}
		}

		bool flag = true;
		bool reverse = false;
		for(int j=0; j<(int)p.size(); j++){
			if(p[j] == 'R'){
				reverse = !reverse;
			}
			else{ //p[j] == 'D'
				if(dq.empty()){
					flag = false;
					break;
				}
				else{
					if(reverse)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}

		//결과 출력
		if(flag){
			if(dq.empty()){
				cout<<"[]"<<'\n';
			}
			else{
				cout<<"[";
				if(reverse){
					for(int j=(int)dq.size()-1; j>0; j--)
						cout<<dq[j]<<",";
					cout<<dq[0];
				}
				else{
					for(int j=0; j<(int)dq.size()-1; j++)
						cout<<dq[j]<<",";
					cout<<dq[dq.size()-1];
				}
				cout<<"]"<<'\n';
			}
		}
		else cout<<"error"<<'\n';
	}

	return 0;
}

