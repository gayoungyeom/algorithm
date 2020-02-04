#include <iostream>
using namespace std;

int main(){
	int x;
	cin>>x;

	int  sum = 0; //분모 + 분자
	int tmp = x;
	while(tmp > 0){
		tmp -= sum;
		sum++;
	}

	int child, parent;
	if(sum % 2 == 0){
		child = (-tmp) + 1;
		parent = sum - child;
	}
	else{
		parent = (-tmp) + 1;
		child = sum - parent;
	}
	
	cout<<child<<"/"<<parent;

	return 0;
}
