#include <iostream>
using namespace std;

int main(){
	string s1, s2;
	cin>>s1>>s2;

	int tmp1 = s1[0];
	s1[0] = s1[2];
	s1[2] = tmp1;

	int tmp2 = s2[0];
	s2[0] = s2[2];
	s2[2] = tmp2;

	int i = atoi(s1.c_str());
	int j = atoi(s2.c_str());

	cout<<max(i, j);

	return 0;
}
