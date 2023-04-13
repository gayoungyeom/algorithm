const WORDS = ['aya', 'ye', 'woo', 'ma'];
const N = WORDS.length;

function solution(babbling) {
    let cnt = 0;
    for(let i = 0; i < babbling.length; i++){
        let idx = 0;
        let flag = true;
        let prev;
        while(idx < babbling[i].length){
            const alpha = babbling[i][idx];
            if(alpha === 'a' && alpha !== prev){
                if(babbling[i].slice(idx, idx + 3) === WORDS[0]){
                    idx += 3;
                    prev = 'a';
                } else {
                    flag = false;
                }
            } else if(alpha === 'y' && alpha !== prev){
                if(babbling[i].slice(idx, idx + 2) === WORDS[1]){
                    idx += 2;    
                    prev = 'y';
                } else {
                    flag = false;
                }              
            } else if(alpha === 'w' && alpha !== prev){
                if(babbling[i].slice(idx, idx + 3) === WORDS[2]){
                    idx += 3;    
                    prev = 'w';
                } else {
                    flag = false;
                }
            } else if(alpha === 'm' && alpha !== prev){
                if(babbling[i].slice(idx, idx + 2) === WORDS[3]){
                    idx += 2;    
                    prev = 'm';
                } else {
                    flag = false;
                }
            } else {
                flag = false;
            }
            if(!flag) break;
        }
        if(flag){
            cnt++;
        }        
    }
    return cnt;
}
