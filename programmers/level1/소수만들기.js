const NUM = 3;
const MAX = 50001;
const check = Array(MAX).fill(false);

const isPrime = () => {
    check[0] = check[1] = true;
    for(let i = 2; i * i <= MAX; i++){
        if(!check[i]){
            for(let j = i + i; j <= MAX; j+=i)
                check[j] = true;
        }
    }
}

function solution(nums) { 
    let ans = 0;
    const tmp = [];
    
    isPrime();
    
    const backtrack = (cur) => {
        if(tmp.length === NUM){
            const sum = tmp.reduce((a, b) => a + b);
            if(!check[sum]) ans++;
            return;
        }

        for(let i = cur; i < nums.length; i++){
            tmp.push(nums[i]);
            backtrack(i + 1);
            tmp.pop();
        }   
    }
    
    backtrack(0);
    
    return ans;
}
