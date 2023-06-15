function solution(m, n, board) {
    board = board.map(str => str.split(''));
    let newBoard = JSON.parse(JSON.stringify(board));
    
    while(1){
        let flag = false;
        for(let i = 0; i < m - 1; i++){
            for(let j = 0; j < n - 1; j++){
                if(board[i][j] === '0') continue;
                
                if(board[i][j] === board[i][j + 1] && board[i][j] === board[i + 1][j] && board[i][j] === board[i + 1][j + 1]){
                    newBoard[i][j] = '0';
                    newBoard[i][j + 1] = '0';
                    newBoard[i + 1][j] = '0';
                    newBoard[i + 1][j + 1] = '0';
                    flag = true;
                }
            }
        }
        
        if(!flag) break;
        
        for(let i = 0; i < n; i++){
            for(let j = m - 1; j > 0; j--){
                if(newBoard[j][i] === '0'){
                    for(let k = j - 1; k >= 0; k--){
                        if(newBoard[k][i] !== '0'){
                            [newBoard[j][i], newBoard[k][i]] = [newBoard[k][i], newBoard[j][i]];
                            break;
                        }
                    }
                }
            }
        }
        
        board = JSON.parse(JSON.stringify(newBoard));
    }
    
    let count = 0;
    
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(newBoard[i][j] === '0'){
                count++;
            }
        }
    }
    
    return count;
}
