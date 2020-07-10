#include <iostream>
using namespace std;

int main(){
	int a, b;
	string s;
	bool result;

	for(int i=1; i<=12000; i++){
		cin>>a>>s>>b;
		if(s == "E") break;

		result = false;
		if((s == ">" && a > b) || (s == ">=" && a >= b) ||
				(s == "<" && a < b) || (s == "<=" && a <= b) ||
				(s == "==" && a == b) || (s == "!=" && a != b))
			result = true;

		if(result)
			cout<<"Case "<<i<<": "<<"true"<<endl;
		else
			cout<<"Case "<<i<<": "<<"false"<<endl;
	}

	return 0;
}
