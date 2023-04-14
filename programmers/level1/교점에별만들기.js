function solution(line) {
    const points = [];
    let xmin = Infinity, ymin = Infinity;
    let xmax = -Infinity, ymax = -Infinity;
    
    const nCr = (cur, tmp) => {
        if(tmp.length === 2){
            const [a1, b1, c1] = line[tmp[0]];
            const [a2, b2, c2] = line[tmp[1]];

            const x = ((b1 * c2) - (c1 * b2)) / ((a1 * b2) - (a2 * b1));
            const y = ((a2 * c1) - (a1 * c2)) / ((a1 * b2) - (a2 * b1));
            
	    //정수 판별을 ~~로 하면 매우 큰 수 일 경우 런타임 에러 발생
            if(Number.isInteger(x) && Number.isInteger(y)){
                points.push([x, y]);
                xmin = Math.min(xmin, x);
                ymin = Math.min(ymin, y);
                xmax = Math.max(xmax, x);
                ymax = Math.max(ymax, y);
            }

            return;
        }
        
        for(let i = cur; i < line.length; i++){
            tmp.push(i);
            nCr(i + 1, tmp);
            tmp.pop();
        }
    }
    
    nCr(0, []);
    
    const newPoints = [];
    for(const point of points){
        const [x, y] = point;
        newPoints.push([ymax - y, x - xmin]);
    }
    
    const w = ymax - ymin + 1;
    const h = xmax - xmin + 1;
    
    let box = Array.from(Array(w), () => Array(h).fill("."));

    for(const [x, y] of newPoints){
        box[x][y] = "*";        
    }

    return box.map(v => v.join(''));
}
