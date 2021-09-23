#include <iostream>
#include <vector>
using namespace std;

vector<long long> lens;
vector<long long> costs;

int main(){
	int n, len, cost;
	long long ans = 0;

	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>len;
		lens.push_back(len);
	}
	for(int i=0; i<n; i++){
		cin>>cost;
		costs.push_back(cost);
	}

	int curCost = costs[0];
	for(int i=1; i<n; i++){
		ans += (curCost * lens[i-1]);
		//다음 도시의 비용이 더 저렴한 경우 cost 업데이트
		if(curCost > costs[i]) curCost = costs[i];
	}

	cout<<ans;

	return 0;
}
