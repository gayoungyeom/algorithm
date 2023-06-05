const ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".split('');

function solution(msg) {
    let ans = [];
    while(msg.length > 0){
        for(let i = msg.length; i > 0; i--){
            const w = msg.slice(0, i);
            const idx = ALPHA.indexOf(w);
            if(idx !== -1){
                ans.push(idx + 1);
                ALPHA.push(w + msg[i]);
                msg = msg.slice(i);
                break;
            }
        }
    }
    return ans;
}
