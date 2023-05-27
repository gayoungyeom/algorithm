const MAX = 100001;

function solution(cacheSize, cities) {
    let runTime = 0;
    let cache = [...Array(cacheSize).fill('')];
    let used = [...Array(cacheSize).fill(0)];
    
    for(let i = 0; i < cities.length; i++){
        const city = cities[i].toUpperCase();
        const hitIndex = cache.indexOf(city);
                
        if(hitIndex !== -1){ //hit
            used[hitIndex] = i + 1;
            runTime += 1;
        } else{ //miss
            const lru = used.indexOf(Math.min(...used));
            cache[lru] = city;
            used[lru] = i + 1;
            runTime += 5;
        }
    }
    
    return runTime;
}
