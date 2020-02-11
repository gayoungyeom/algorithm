#include <iostream>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	int cards[n];
	for(int i=0; i<n; i++)
		cin>>cards[i];

	int max = 0;
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				int tmp = cards[i] + cards[j] + cards[k];
				if(max < tmp && tmp <= m){
					max = tmp;
				}
			}
		}
	}
	cout<<max;

	return 0;
}
