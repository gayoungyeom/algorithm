#include <iostream>
using namespace std;

int main(){
	int T, n;
	cin>>T;

	for(int i=0; i<T; i++){
		cin>>n;
		int score[n];
		int sum = 0;
		for(int j=0; j<n; j++){
			cin>>score[j];
			sum += score[j];
		}
		double average = (double)sum / n;
		int cnt = 0;
		for(int j=0; j<n; j++){
			if(average < score[j]) cnt++;
		}
		double rate = (double)cnt / n * 100;
		printf("%.3f%%\n", rate);
	}

    return 0;
}
