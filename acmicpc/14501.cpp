#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> t;
vector<int> p;

void go(int day, int price){
	if(day == n){ //price가 day-1일까지의 수익이므로 day=n이 종료조건임
		ans = max(ans, price);
		return;
	}
	if(day > n) return;
	go(day + t[day], price + p[day]); //day 상담한 경우
	go(day + 1, price); //day 상담하지 않은 경우
}

int main(){
	cin>>n;
	int ti, pi;
	for(int i=0; i<n; i++){
		cin>>ti>>pi;
		t.push_back(ti);
		p.push_back(pi);
	}
	go(0, 0);
	cout<<ans<<'\n';
	return 0;
}

