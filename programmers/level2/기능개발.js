function solution(progresses, speeds) {
    const s = [];
    for(let i = 0; i < progresses.length; i++){
        s.push(Math.ceil((100 - progresses[i]) / speeds[i]));
    }
    
    const deployment = [];
    let cur = s[0];
    let cnt = 1;
    for(let i = 1; i < s.length; i++){
        if(cur < s[i]){
            cur = s[i];
            deployment.push(cnt);
            cnt = 1;
        } else{
            cnt++;
        }
    }
    deployment.push(cnt);
    
    return deployment;
}
