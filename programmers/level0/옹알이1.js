const WORDS = ["aya", "ye", "woo", "ma"];

const permutation = (arr, r) => {
    let result = [];
    
    const dfs = (v) => {
        if(v.length === r){
            result.push(Array.from(v));
            return;
        }
        for(let i = 0; i < arr.length; i++){
            if(v.includes(arr[i])) continue;
            v.push(arr[i]);
            dfs(v);
            v.pop();
        }
    }
    
    dfs([]);
    return result;
}

//1. 순열 활용
function solution(babbling) {
    const WORDS_COMB = [];
    for(let i = 1; i <= 4; i++){
        for(const word of permutation(WORDS, i)){
            WORDS_COMB.push(word.join(''));
        }
    }
    
    return babbling.filter(bab => WORDS_COMB.includes(bab)).length;
}

//2. 정규식 활용
function solution(babbling) {
    let answer = 0;
    const regex = /^(aya|ye|woo|ma)+$/;
    
    return babbling.filter(bab => regex.test(bab)).length;
}
