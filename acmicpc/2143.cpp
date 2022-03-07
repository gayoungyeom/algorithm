#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t, n, m;
	cin>>t;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>m;
	vector<int> b(m);
	for(int i=0; i<m; i++)
		cin>>b[i];

	vector<int> subA;
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum += a[j];
			subA.push_back(sum);
		}
	}
	vector<int> subB;
	for(int i=0; i<m; i++){
		int sum = 0;
		for(int j=i; j<m; j++){
			sum += b[j];
			subB.push_back(sum);
		}
	}

	sort(subA.begin(), subA.end());
	sort(subB.begin(), subB.end());
	reverse(subB.begin(), subB.end());

	int i = 0;
	int j = 0;
	long long ans = 0;
	while(i < subA.size() && j < subB.size()){
		if(subA[i] + subB[j] < t){
			i++;
		} else if(subA[i] + subB[j] == t){
			long long c1 = 1;
			long long c2 = 1;
			i++;
			j++;
			while(i < subA.size() && subA[i] == subA[i-1]){
				c1++;
				i++;
			}
			while(j < subB.size() && subB[j] == subB[j-1]){
				c2++;
				j++;
			}
			ans += c1*c2;
		} else{
			j++;
		}
	}

	cout<<ans<<'\n';

	return 0;
}

