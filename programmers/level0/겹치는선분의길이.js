const MAX = 201;
const TOPOSITIVE = 100;

function solution(lines) {
    const overlap = Array(MAX).fill(0);
    
    for(const line of lines){
        for(let i = line[0]; i < line[1]; i++){
            overlap[i + TOPOSITIVE]++;
        }
    }
    
    return overlap.filter(o => o > 1).length;
}
