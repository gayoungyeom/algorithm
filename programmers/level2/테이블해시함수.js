function solution(data, col, row_begin, row_end) {
    data.sort((a, b) => a[col - 1] === b[col - 1] ? b[0] - a[0] : a[col - 1] - b[col - 1]);
    
    let hash = 0;
    
    for(let i = row_begin - 1; i < row_end; i++){
        let s = 0;
        for(const v of data[i]){
            s += (v % (i + 1));
        }
        
        hash ^= s; //XOR
    }
    
    return hash;
}
