#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n+1];
	stack<int> s;
	vector<char> v;
	for(int i=1; i<=n; i++)
		cin>>arr[i];

	int idx = 1;
	for(int i=1; i<=n; i++){
		for(int j=idx; j<=arr[i]; j++){
			s.push(j);
			v.push_back('+');
			idx++;
		}
		if(arr[i] == s.top()){
			s.pop();
			v.push_back('-');
		}
	}

	if(s.empty()) {
		for(int i=0; i<(int)v.size(); i++)
			cout<<v[i]<<'\n';
	} else cout<<"NO"<<'\n';

	return 0;
}

