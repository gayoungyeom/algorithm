const ENG2NUM = {
    "ze": {val: 0, len: 4},
    "on": {val: 1, len: 3},
    "tw": {val: 2, len: 3},
    "th": {val: 3, len: 5},
    "fo": {val: 4, len: 4},
    "fi": {val: 5, len: 4},
    "si": {val: 6, len: 3},
    "se": {val: 7, len: 5},
    "ei": {val: 8, len: 5},
    "ni": {val: 9, len: 4},
}

function solution(numbers) {
    let ans = "";
    let i = 0;
    while(i < numbers.length){
        const eng = numbers.substring(i, i + 2);
        const num = ENG2NUM[eng].val;
        const numLen = ENG2NUM[eng].len;
        
        ans += num;
        numbers.slice(i + numLen);
        i += numLen;
    }
    return Number(ans);
}
