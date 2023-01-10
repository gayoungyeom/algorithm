const DIR = {
    "up": {x: 0, y: 1},
    "down": {x: 0, y: -1},
    "left": {x: -1, y: 0},
    "right": {x: 1, y: 0}
}

function solution(keyinput, board) {
    let start = [0, 0];
    
    const bx = (board[0] - 1) / 2;
    const by = (board[1] - 1) / 2;
    
    keyinput.forEach(key => {
        const nx = start[0] + DIR[key].x;
        const ny = start[1] + DIR[key].y;
        
        if(nx < -bx || nx > bx || ny < -by || ny > by)
            return;
        
        start[0] = nx;
        start[1] = ny;
    });
    
    return start;
}
