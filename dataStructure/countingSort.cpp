/*
 * A: 초기 배열
 * B: 정렬된 배열
 * C: counting
 */
#include <iostream>
using namespace std;

int C[10001];

void cntingSort(int A[], int B[], int n, int k){
	for(int i=0; i<n; i++) C[A[i]]++;
	for(int i=1; i<=k; i++) C[i] += C[i-1];
	for(int i=n-1; i>=0; i--){
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}

int main(){
	int n;
	cin>>n;

	int* A = new int[n];
	int* B = new int[n];
	int k = 0; //수의 범위 중 최대 값

	for(int i=0; i<n; i++){
		cin>>A[i];
		k = max(k, A[i]);
	}

	cntingSort(A, B, n, k);

	for(int i=0; i<n; i++)
		cout<<B[i]<<'\n';

	delete[] A;
	delete[] B;

	return 0;
}

