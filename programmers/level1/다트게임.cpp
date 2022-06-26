#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int total = 0;
    int sum = 0;
    int prev = 0;
    for(int i=0; i<(int)dartResult.size(); i++){
        char cur = dartResult[i];
        if(cur >= '0' && cur <= '9'){ //숫자
            prev = sum;
            sum = cur - '0';
            if(dartResult[i+1] == '0'){ //10인 경우 예외 처리
                sum = 10;
                i++;
            }
        } else if(cur == 'S' || cur == 'D' || cur == 'T'){ //보너스
            int bonus = 1;
            if(cur == 'D')
                bonus = 2;
            else if(cur == 'T')
                bonus = 3;
            sum = pow(sum, bonus);
            
            //옵션이 있는 경우
            char next = dartResult[i+1];
            if(next == '*'){
                total -= prev;
                sum *= 2;
                prev *= 2;
                total += (sum + prev);
                i++;
            } else if(next == '#'){
                sum = -sum;
                total += sum;
                i++;
            } else{
                total += sum;
            }
        }
    }
    
    return total;
}
