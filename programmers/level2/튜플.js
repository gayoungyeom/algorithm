function solution(s) {
    const arr = s.slice(2, - 2).split('},{');
    arr.sort((a, b) => a.length - b.length);
    
    let tuple = [];
    
    for(const a of arr){
        const cur = a.split(',');
        for(const b of cur){
            if(!tuple.includes(b)){
                tuple.push(b);
            }
        }
    }
    
    return tuple.map(Number);
}
