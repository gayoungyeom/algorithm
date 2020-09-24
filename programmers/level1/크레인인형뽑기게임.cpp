#include <string>
#include <vector>
using namespace std;

vector<int> bgn; //바구니

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size(); 
    int m = moves.size();
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[j][moves[i]-1] != 0){
                if(bgn.size() > 0 && board[j][moves[i]-1] == bgn.back()){
                    answer += 2;
                    bgn.pop_back();
                } else{
                    bgn.push_back(board[j][moves[i]-1]);
                }
                board[j][moves[i]-1] = 0; 
                break;
            }
        }
    }
      
    return answer;
}
