#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GCD(int a, int b){
	if(b == 0) return a;
	return GCD(b, a % b);
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	int num[n];
	for(int i=0; i<n; i++)
		cin>>num[i];

	sort(num, num + n);

	int gcd = num[1] - num[0];
	for(int i=2; i<n; i++){
		gcd = GCD(gcd, num[i] - num[i-1]);
	}

	vector<int> v;
	for(int i=2; i*i<=gcd; i++){
		if(gcd % i == 0){
			v.push_back(i);
			v.push_back(gcd / i);
		}
	}
	v.push_back(gcd);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(unsigned int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";

	return 0;
}

