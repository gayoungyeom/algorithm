function solution(elements) {
    const n = elements.length;
    const result = new Set();
    
    for(let len = 1; len <= n; len++){ //길이
        for(let i = 0; i < n; i++){ //시작 인덱스
            let sum = 0;
            for(let j = i; j < i + len; j++){
                sum += elements[(j % n)];
            }
            result.add(sum);
        }
    }
    return result.size;
}
