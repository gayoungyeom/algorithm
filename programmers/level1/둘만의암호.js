const ALPHA = 'abcdefghijklmnopqrstuvwxyz';

function solution(s, skip, index) {
    const filtered = [...ALPHA].filter(v => !skip.includes(v));
    
    let result = "";
    for(let i = 0; i < s.length; i++){
        const curIdx = filtered.findIndex(v => v === s[i]);
        result += filtered[(curIdx + index) % filtered.length];
    }
    
    return result;
}
