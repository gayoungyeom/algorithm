//짝수 -> 마지막 비트를 1로 변경
//홀수 -> 뒤에서부터 반복문 돌다가 0이 등장하면 그 부분을 1로 변경, 그 다음 위치를 0으로 변경
function solution(numbers) {
    const result = [];
    
    for(const number of numbers){
        if(number % 2 === 0) result.push(number + 1);
        else {
            const bits = number.toString(2);

            let idx = 0;
            for(let i = bits.length - 1; i >= 0; i--){
                if(bits[i] === '0'){
                    idx = i;
                    break;
                }
            }
            
            let len = bits.length;
            if(idx === 0) len++;
            
            result.push(number + Math.pow(2, len - idx - 2));
        }
    }
    
    return result;
}
