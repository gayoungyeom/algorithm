//추가) every와 some을 활용할 수도 있음
function solution(arrayA, arrayB) {   
    const getDivisor = (num) => {
        const result = [];
        for(let i = 1; i * i <= num; i++){
            if(num % i === 0){
                if(i !== 1) result.push(i);
                result.push(num / i);
            }
            if(i * i === num) result.pop();
        }
        return result.sort((a, b) => b - a);
    }
    
    const check = (divArr, arrA, arrB) => {
        for(const div of divArr){
            let flag = true;
            for(const a of arrA){
                if(a % div !== 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(const b of arrB){
                    if(b % div === 0){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) return div;
        }
        return 0;
    }
    
    arrayA.sort((a, b) => a - b);
    arrayB.sort((a, b) => a - b);
    
    const divA = getDivisor(arrayA[0]);
    const divB = getDivisor(arrayB[0]);
    
    return Math.max(0, check(divA, arrayA, arrayB), check(divB, arrayB, arrayA));
}
