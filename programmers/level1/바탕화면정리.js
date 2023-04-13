function solution(wallpaper) {
    const n = wallpaper.length;
    const m = wallpaper[0].length;
    
    let lux = n, luy = m, rdx = 0, rdy = 0;
    
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if(wallpaper[i][j] === "#"){
                lux = Math.min(lux, i);
                luy = Math.min(luy, j);
                rdx = Math.max(rdx, i + 1);
                rdy = Math.max(rdy, j + 1);
            }
        }
    }
    
    return [lux, luy, rdx, rdy];
}
