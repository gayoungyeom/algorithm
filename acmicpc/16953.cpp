//long long!!
#include <iostream>
using namespace std;

int go(long long a, long long b, int cnt){
	if(a == b) return cnt;
	if(a > b) return -1;

	int t1 = go(a*2, b, cnt+1);
	int t2 = go(10*a+1, b, cnt+1);

	if(t1 == -1 && t2 == -1) return -1;
	if(t1 == -1) return t2;
	if(t2 == -1) return t1;
	return min(t1, t2);
}

int main(){
	int a, b;
	cin>>a>>b;
	cout<<go(a, b, 1)<<'\n';
	return 0;
}

