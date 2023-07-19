function solution(k, ranges) {
    //우박수열 구하기
    const seq = [];
    const getSeq = (cur) => {
        seq.push(cur);
        if(cur === 1) return;
        
        if(cur % 2 === 0) getSeq(cur / 2);
        else getSeq(cur * 3 + 1);
    } 
    
    getSeq(k);
    
    //넓이 구하기
    const area = [];
    for(let i = 0; i < seq.length - 1; i++){
        area.push((seq[i] + seq[i + 1]) / 2);
    }
    
    //구간에 대한 정적분 구하기
    const result = [];
    for(const range of ranges){
        const [x1, x2] = [range[0], seq.length + range[1] - 1];
        if(x1 > x2) {
            result.push(-1.0);
            continue;
        }
        
        let width = 0;
        for(let i = x1; i < x2; i++){
            width += area[i];
        }
        result.push(width.toFixed(1));
    }
    
    return result;
}
