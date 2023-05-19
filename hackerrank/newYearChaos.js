function minimumBribes(q) {
    let result = '';
    const n = q.length;
    let bribeCnt = [...Array(n + 1).fill(0)];

    let flag = true;
    for(let j = 0; j < n - 1; j++){
        if(q[j] > q[j + 1]){
            if(bribeCnt[q[j]] >= 2){
                flag = false;
                result += 'Too chaotic';
                break;
            }
            bribeCnt[q[j]]++;
            [q[j], q[j + 1]] = [q[j + 1], q[j]];
            
            j -= 2; //only Two are compared
        }
    }
    if(flag) result += `${bribeCnt.reduce((a, b) => a + b)}`;

    console.log(result);
}
