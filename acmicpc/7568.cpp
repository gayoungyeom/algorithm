#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> body;
vector<int> ranks;

int main(){
	int n, x, y;
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>x>>y;
		body.push_back(make_pair(x, y));
	}

	for(int i=0; i<n; i++){
		int cnt = 0;
		for(int j=0; j<n; j++){
			if(body[i].first < body[j].first && body[i].second < body[j].second)
				cnt++;
		}
		ranks.push_back(cnt + 1);
	}

	for(int i=0; i<n; i++)
		cout<<ranks[i]<<" ";

	return 0;
}

