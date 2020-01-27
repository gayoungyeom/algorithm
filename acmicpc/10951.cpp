//cin.eof(): cin으로 입력받은 값이 없으면 true, 그렇지 않으면 false 반환
#include <iostream>
using namespace std;

int main(){
	int A, B;

	while(1){
		cin>>A>>B;
		if(cin.eof()) break;
		cout<<A + B<<endl;
	}
    return 0;
}

