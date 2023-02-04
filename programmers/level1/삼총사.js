const NUM = 3;

//1. tmp 전역 + push/pop 직접
function solution(number) {
    let ans = 0;
    const tmp = [];
    
    const backtrack = (cur) => {
        if(tmp.length === NUM){
            ans += tmp.reduce((a, b) => a + b) ? 0 : 1;
            return;
        }

        for(let i = cur; i < number.length; i++){
            tmp.push(number[i]);
            backtrack(i + 1);
            tmp.pop();
        }   
    }
    
    backtrack(0);
    
    return ans;
}

//2. tmp를 인자로 + push/pop을 spread로 한번에 처리
function solution(number) {
    let ans = 0;
    
    const backtrack = (tmp, cur) => {
        if(tmp.length === NUM){
            ans += tmp.reduce((a, b) => a + b) ? 0 : 1;
            return;
        }

        for(let i = cur; i < number.length; i++){
            backtrack([...tmp, number[i]], i + 1);
        }   
    }
    
    backtrack([], 0);
    
    return ans;
}
