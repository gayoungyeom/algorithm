#include <iostream>
using namespace std;

void check(int max, int s2, int s3){
	if((max * max) == (s2 * s2 + s3 * s3))
		cout<<"right"<<endl;
	else
		cout<<"wrong"<<endl;
}

int main(){
	int s1, s2, s3;

	while(1){
		cin>>s1>>s2>>s3;
		if(s1 == 0) break;

		int arr[3] = {s1, s2, s3};
		int max = arr[0];
		int idx = 0;
		for(int i=1; i<3; i++){
			if(arr[i] > max){
				max = arr[i];
				idx = i;
			}
		}

		if(idx == 0) check(s1, s2, s3);
		else if(idx == 1) check(s2, s1, s3);
		else check(s3, s1, s2);
	}

	return 0;
}

