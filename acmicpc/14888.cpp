#include <iostream>
#include <vector>
#include <limits> //std::numeric_limits header
using namespace std;

int n;
int A[12], op[4];
int Min = std::numeric_limits<int>::max();
int Max = std::numeric_limits<int>::min();

void backtrack(int deapth, int result){
	if(deapth == n-1){
		if(result < Min) Min = result;
		if(result > Max) Max = result;
		return;
	}

	for(int i=0; i<4; i++){
		if(op[i]){
			op[i]--;
			switch(i){
			case 0:
				backtrack(deapth + 1, result + A[deapth + 1]);
				break;
			case 1:
				backtrack(deapth + 1, result - A[deapth + 1]);
				break;
			case 2:
				backtrack(deapth + 1, result * A[deapth + 1]);
				break;
			case 3:
				backtrack(deapth + 1, result / A[deapth + 1]);
				break;
			}
			op[i]++;
		}
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>A[i];

	for(int i=0; i<4; i++)
		cin>>op[i];

	backtrack(0, A[0]);

	cout<<Max<<endl;
	cout<<Min<<endl;

	return 0;
}

