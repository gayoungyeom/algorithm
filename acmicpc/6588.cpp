#include <iostream>
using namespace std;

const int MAX = 1000001;
bool check[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	check[0] = check[1] = true;
	for(int i=2; i*i<=MAX; i++){
		if(check[i] == false){
			for(int j=i+i; j<=MAX; j+=i)
				check[j] = true;
		}
	}

	int n;
	while(cin>>n, n){
		for(int j=3; j<=n; j++){
			if(!check[j] && !check[n-j]){
				cout<<n<<" = "<<j<<" + "<<n-j<<'\n';
				break;
			}
		}
	}
	return 0;
}
