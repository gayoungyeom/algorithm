function solution(s) {
    const result = [];
    
    const words = s.split(' ');
    for(const word of words){
        const jadenCase = word.slice(0, 1).toUpperCase() + word.slice(1).toLowerCase();
        result.push(jadenCase);
    }
    
    return result.join(' ');
}
