function solution(park, routes) {
    const dir = {
        N: [-1, 0],
        S: [1, 0],
        W: [0, -1],
        E: [0, 1],
    }
    
    park = park.map(p => p.split(''));
    const h = park.length;
    const w = park[0].length;
    let x, y;
    
    for(let i = 0; i < h; i++){
        for(let j = 0; j < w; j++){
            if(park[i][j] === 'S'){
                x = i;
                y = j;
                break;
            }
        }
    }

    let ans = [x, y];
    for(let i = 0; i < routes.length; i++){
        const [op, n] = routes[i].split(' ');
        const [dx, dy] = dir[op];
        
        let flag = false;
        for(let j = 0; j < Number(n); j++){            
            x += dx;
            y += dy;

            if(x < 0 || x >= h || y < 0 || y >= w || park[x][y] === 'X') {
                flag = true;
                break;
            }
        }
        
        if(flag) [x, y] = ans; //조건 만족 시 업데이트
        else ans = [x, y]; //조건 만족 못하면 초기화
    }

    return ans;
}
