#include <iostream>
using namespace std;

int main(){
	int t, m, n, x, y;
	cin>>t;

	for(int i=0; i<t; i++){
		cin>>m>>n>>x>>y;

		x--;
		y--;
		int j = 0;
		while(1){
			int k = m * j + x; //x 고정 부분만 살펴보기
			if(k % n == y){
				cout<<k+1<<'\n';
				break;
			}
			if(k > n * m){
				cout<<-1<<'\n';
				break;
			}
			j++;
		}
	}

	return 0;
}
