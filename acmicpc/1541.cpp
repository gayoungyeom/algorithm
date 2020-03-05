#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
	string exp;
	cin>>exp;

	int num = 0;
	bool flag = false;
	string tmp = "";
	for(int i=0; i <=(int)exp.length(); i++){
		if(exp[i] == '-'){
			num += stoi(tmp);
			v.push_back(num);
			num = 0;
			tmp = "";
			flag = true;
		}
		else if(exp[i] == '+'){
			num += stoi(tmp);
			tmp = "";
			flag = false;
		}
		else{
			tmp += exp[i];
		}
	}

	if(flag){ //마지막 연산자가 -인 경우
		v.push_back(stoi(tmp));
	}
	else{ //마지막 연산자가 +인 경우
		num += stoi(tmp);
		v.push_back(num);
	}

	int ans = v[0];
	for(int i=1; i<(int)v.size(); i++)
		ans -= v[i];
	cout<<ans<<endl;

	return 0;
}

