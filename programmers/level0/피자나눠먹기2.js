const PIECE = 6;

function solution(n) {    
    for(let i=1; i<=PIECE; i++){
        const eat = n * i;
        if(eat % PIECE === 0)
            return ~~(eat / PIECE);
    }
}
