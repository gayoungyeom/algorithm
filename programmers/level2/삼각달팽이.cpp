#include <iostream>
#include <vector>
using namespace std;

int arr[1001][1001];
vector<int> v;

vector<int> solution(int n) {
    vector<int> answer;
	int num = 1;
	int row = 0;
	int col = 0;
	int end = n - 1;
	int max = n * (n + 1) / 2;

	arr[row][col] = num;
	num++;

	//row++
	for(int i=0; i<end; i++){
		row++;
		if(!arr[row][col]){
			arr[row][col] = num;
			num++;
		}
	}

	//col++
	for(int i=0; i<end; i++){
		col++;
		if(!arr[row][col]){
			arr[row][col] = num;
			num++;
		}
	}

	end--;
	//row--, col--
	for(int i=0; i<end; i++){
		row--;
		col--;
		if(!arr[row][col]){
			arr[row][col] = num;
			num++;
		}
	}

	while(num != max+1){
		end--;
		//row++
		for(int i=0; i<end; i++){
			row++;
			if(!arr[row][col]){
				arr[row][col] = num;
				num++;
			}
		}

		end--;
		//col++
		for(int i=0; i<end; i++){
			col++;
			if(!arr[row][col]){
				arr[row][col] = num;
				num++;
			}
		}

		end--;
		//row--, col--
		for(int i=0; i<end; i++){
			row--;
			col--;
			if(!arr[row][col]){
				arr[row][col] = num;
				num++;
			}
		}
	}


	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j]){
				answer.push_back(arr[i][j]);
			}
		}
	}
    return answer;
}
