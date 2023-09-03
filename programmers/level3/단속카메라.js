function solution(routes) {
    routes.sort((a, b) => a[1] - b[1]);
    
    let camera = 1;
    let cur = routes[0][1];
    
    for(let i = 1; i < routes.length; i++){
        const [inn, out] = routes[i];

        if(cur - inn < 0){
            camera++;
            cur = out;
        }
    }
    
    return camera;
}
