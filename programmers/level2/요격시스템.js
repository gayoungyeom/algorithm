function solution(targets) {
    targets.sort((a, b) => a[1] - b[1]); //end기준으로 정렬
    let shot = targets[0][1];
    let count = 1;
    
    for(let i = 1; i < targets.length; i++){
        const [s, e] = targets[i];
        
        if(shot <= s){
            shot = e;
            count++;
        }
    }
    
    return count;
}
