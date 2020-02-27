a//1은 소인수분해 할 수가 없다!
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void func(int n){
	if(n == 1){
		for(unsigned int i=0; i<v.size(); i++)
			cout<<v[i]<<'\n';
		exit(0);
	}
	for(int i=2; i<=n; i++){
		if(n % i == 0){
			v.push_back(i);
			func(n / i);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;
	func(n);
	return 0;
}

