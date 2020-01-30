#include <iostream>
using namespace std;
const int MAX = 10000;

int d[MAX+1];

void selfNum(){
	for(int i=1; i<=MAX; i++){
		int result = i;
		int tmp = i;
		while(tmp != 0){
			result += tmp % 10;
			tmp /= 10;
		}
		d[result] = 1;
	}
}

int main(){
	selfNum();
	for(int i=1; i<=MAX; i++){
		if(!d[i]) cout<<i<<endl;
	}
	return 0;
}
