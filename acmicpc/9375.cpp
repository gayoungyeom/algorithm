#include <iostream>
#include <map>
using namespace std;

int main(){
	int T, n;
	string name, type;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>n;
		map<string, int> m; //types
		for(int j=0; j<n; j++){
			cin>>name>>type;
			if(m.empty())
				m.insert(make_pair(type, 1));
			else{
				if(m.count(type) == 0) //새로운 type
					m.insert(make_pair(type, 1));
				else
					(m.find(type)->second)++;
			}
		}
		int ans = 1;
		for(auto it=m.begin(); it!=m.end(); it++){
			if(it->second == 1)
				ans *= 2;
			else
				ans *= (it->second + 1);
		}
		cout<<ans - 1<<endl;
	}

	return 0;
}

