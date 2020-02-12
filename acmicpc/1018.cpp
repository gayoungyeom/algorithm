#include <iostream>
using namespace std;

int main(){
	int m, n;
	cin>>m>>n;

	char board[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>board[i][j];
		}
	}

	int changeCnt = 999999;
	for(int i=0; i<=m-8; i++){
		for(int j=0; j<=n-8; j++){
			int startM = i;
			int startN = j;
			int cntW = 0;
			int cntB = 0;

			//흰색으로 시작하는 경우
			for(int p=startM; p<startM+8; p++){
				for(int q=startN; q<startN+8; q++){
					if(p % 2 == 0){ //짝수 행
						if(q % 2 == 0){ //짝수 열
							if(board[p][q] != 'W')
								cntW++;
						}
						else{ //홀수 열
							if(board[p][q] != 'B')
								cntW++;
						}
					}
					else{ //홀수 행
						if(q % 2 == 0){ //짝수 열
							if(board[p][q] != 'B')
								cntW++;
						}
						else{ //홀수 열
							if(board[p][q] != 'W')
								cntW++;
						}
					}
				}
			}

			//검은색으로 시작하는 경우
			for(int p=startM; p<startM+8; p++){
				for(int q=startN; q<startN+8; q++){
					if(p % 2 == 0){ //짝수 행
						if(q % 2 == 0){ //짝수 열
							if(board[p][q] != 'B')
								cntB++;
						}
						else{ //홀수 열
							if(board[p][q] != 'W')
								cntB++;
						}
					}
					else{ //홀수 행
						if(q % 2 == 0){ //짝수 열
							if(board[p][q] != 'W')
								cntB++;
						}
						else{ //홀수 열
							if(board[p][q] != 'B')
								cntB++;
						}
					}
				}
			}
		changeCnt = min(changeCnt, min(cntW, cntB));
		}
	}

	cout<<changeCnt;

	return 0;
}

