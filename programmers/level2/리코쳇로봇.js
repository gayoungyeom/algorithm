function solution(board) {
    board = board.map(b => b.split(''));
    const n = board.length; 
    const m = board[0].length;
    
    let start, end;
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(board[i][j] === 'R'){
                start = [i, j];
                board[i][j] = 0;
            }
            if(board[i][j] === 'G'){
                end = [i, j];
                board[i][j] = '.';
            }
        }
    }
    
    const q = [];
    q.push(start);
    
    while(q.length !== 0){
        const [x, y] = q.shift();
   
        //left
        for(let i = y - 1; i >= 0; i--){
            if(board[x][i] === 'D'){
                if(board[x][i + 1] === '.'){
                    board[x][i + 1] = board[x][y] + 1;
                    q.push([x, i + 1]);
                }
                break;
            }
            
            
            if(i === 0 && board[x][i] === '.'){
                board[x][i] = board[x][y] + 1;;
                q.push([x, i]);
            }
        }
        
        //right
        for(let i = y + 1; i < m; i++){
            if(board[x][i] === 'D'){
                if(board[x][i - 1] === '.'){
                    board[x][i - 1] = board[x][y] + 1;
                    q.push([x, i - 1]);
                }
                break;
            }
            
            if(i === m - 1 && board[x][i] === '.'){
                board[x][i] = board[x][y] + 1;;
                q.push([x, i]);
            }
        }
        
        //top
        for(let i = x - 1; i >= 0; i--){
            if(board[i][y] === 'D'){
                if(board[i + 1][y] === '.'){
                    board[i + 1][y] = board[x][y] + 1;
                    q.push([i + 1, y]);
                }
                break;
            }
            
           if(i === 0 && board[i][y] === '.'){
                board[i][y] = board[x][y] + 1;;
                q.push([i, y]);
            }
        }
        
        //bottom
        for(let i = x + 1; i < n; i++){
            if(board[i][y] === 'D'){
                if(board[i - 1][y] === '.'){
                    board[i - 1][y] = board[x][y] + 1;
                    q.push([i - 1, y]);
                }
                break;
            }
            
           if(i === n - 1 && board[i][y] === '.'){
                board[i][y] = board[x][y] + 1;;
                q.push([i, y]);
                break;
            }
        }
    }
    
    return board[end[0]][end[1]] === '.' ? -1 : board[end[0]][end[1]];
}
