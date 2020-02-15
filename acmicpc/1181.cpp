#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

bool compare(const string & s1, const string &s2){
	int size1 = s1.size();
	int size2 = s2.size();
	if(size1 == size2) return s1 < s2;
	return size1 < size2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin>>n;

	string s;
	for(int i=0; i<n; i++){
		cin>>s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);

	for(int i=0; i<n; i++){
		if(v[i] == v[i+1]) continue;
		cout<<v[i]<<'\n';
	}

	return 0;
}

