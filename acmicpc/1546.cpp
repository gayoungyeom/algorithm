#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int sbj[n];
	double newsbj[n];
	for(int i=0; i<n; i++)
		cin>>sbj[i];

	int max = 0;
	for(int i=0; i<n; i++)
		if(max < sbj[i]) max = sbj[i];

	double sum = 0;
	for(int i=0; i<n; i++){
		newsbj[i] = (double)sbj[i] / max * 100;
		sum += newsbj[i];
	}
	double average = sum / n;
	cout<<average;

    return 0;
}
