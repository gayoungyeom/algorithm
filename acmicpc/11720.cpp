//정수를 문자열로 입력받는 문제
//일반적인 정수 자료형에 담기 너무 큰 경우
#include <iostream>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += (s[i] - 48);
	}
	cout<<sum;
	return 0;
}
