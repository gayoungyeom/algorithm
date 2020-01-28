#include <iostream>
using namespace std;

void BubbleSort(int a[], int size);

int main(){
	int n;
	cin>>n;
	int* a = new int[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	BubbleSort(a, n);

	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";

	return 0;
}

void BubbleSort(int a[], int n){
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(a[j]>a[j+1]){
				int temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}

