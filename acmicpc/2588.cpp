#include <iostream>
using namespace std;

int main(){
	int num1;
	int num2;
	int tmp;
	int result;
	int sum = 0;

	cin>>num1>>num2;

	for(int i=1; i<=100; i=i*10){
		tmp = num2 % 10;
		result = num1 * tmp;
		cout<<result<<endl;
		num2 /= 10;
		sum += (result * i);
	}
	cout<<sum;

	return 0;
}
