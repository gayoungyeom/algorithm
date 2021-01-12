//c++은 big integer를 지원하지 않는다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> result;

int main() {
	string A, B;
	cin>>A>>B;

	int len = max(A.size(), B.size());
	int carry = 0;

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	while(A.size() < B.size())
		A += '0';
	while(B.size() < A.size())
		B += '0';

	int add;
	for(int i=0; i<len; i++){
		int intA = A[i] - '0';
		int intB = B[i] - '0';
		add = intA + intB + carry;
		result.push_back(add % 10);
		carry = add / 10;
	}

	if(carry > 0)
		cout<<carry;
	for(int i=(int)result.size()-1; i>=0; i--)
		cout<<result[i];

	return 0;
}

