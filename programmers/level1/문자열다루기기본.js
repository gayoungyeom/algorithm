function solution(s) {
    if(s.includes('e') || s.includes('E')) return false;   
    return !isNaN(s) && (s.length === 4 || s.length === 6);
}
