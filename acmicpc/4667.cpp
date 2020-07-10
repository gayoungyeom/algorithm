#include <iostream>
using namespace std;

double dep[101];

int main(){
	double duration, down_payment, loan, num_of_depreciation; //대출기간, 계약금, 대출금, 감가상각기록수
	int month; //월 번호
	double depreciation; //감가상각비

	while(1){
		cin>>duration>>down_payment>>loan>>num_of_depreciation;
		if(duration < 0) break;

		for(int i=0; i<=duration; i++){
			dep[i] = 0;
		}
		while(num_of_depreciation--){
			cin>>month>>depreciation;
			dep[month] = depreciation;
		}
		for(int i=0; i<duration; i++){
			if(dep[i] == 0)
				dep[i] = dep[i-1];
		}

		double ppm = loan / duration; //payment per month
		double car_value = (down_payment + loan) * (1 - dep[0]);

		int cur = 0;
		while(car_value < loan){
			cur++;
			loan -= ppm;
			car_value *= (1 - dep[cur]);
		}

		if(cur == 1) cout<<cur<<" month"<<endl;
		else cout<<cur<<" months"<<endl;
	}
	return 0;
}
