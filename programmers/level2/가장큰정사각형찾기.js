function solution(board) {
    const n = board.length;
    const m = board[0].length;
    let d = JSON.parse(JSON.stringify(board)); //d[i][j]: (i, j)가 정사각형의 끝점일 때 최대 길이
    
    let max = Boolean(board.find(b => b.find(v => v))); //1이 존재하면 최소 넓이는 1, 아니면 0
    
    for(let i = 1; i < n; i++){
        for(let j = 1; j < m; j++){
            if(board[i][j] && board[i][j - 1] && board[i - 1][j] && board[i - 1][j - 1]){
                d[i][j] = Math.min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + 1;
                max = Math.max(max, d[i][j]);
            }
        }
    }
    
    return max * max;
}
