#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
	int n;
	cin>>n;

	int i = 0;
	while(n > 0){
		v.push_back(n % 10);
		n /= 10;
		i++;
	}

	//vector 역순 정렬
	sort(v.begin(), v.end(), greater<int>());

	for(int j=0; j<i; j++)
		cout<<v[j];

	return 0;
}

