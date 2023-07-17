function solution(places) {
    const result = [];
    
    for(const place of places){
        const people = [];
        for(let i = 0; i < 5; i++){
            for(let j = 0; j < 5; j++){
                if(place[i][j] === 'P'){
                    people.push([i, j]);
                }
            }
        }
        
        let flagAll = true;
        for(let i = 0; i < people.length - 1; i++){
            let flag = true;
            const [x1, y1] = people[i];
            
            for(let j = i + 1; j < people.length; j++){
                const [x2, y2] = people[j];
                const dist = Math.abs(x1 - x2) + Math.abs(y1 - y2);
                
                if(dist > 2) continue;
                
                if(dist === 1){
                    flag = false;
                    break;
                }

                if(x1 === x2 || y1 === y2){ //일직선
                    const mx = (x1 + x2) * 0.5;
                    const my = (y1 + y2) * 0.5;
                    
                    //중앙에 파티션이 없는 경우
                    if(place[mx][my] !== 'X'){
                        flag = false;
                        break;
                    }
                } else{ //대각선
                    //반대 대각선에 파티션이 없는 경우
                    if(place[x1][y2] !== 'X' || place[x2][y1] !== 'X'){
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) {
                flagAll = false;
                break;
            }
        }
        result.push(flagAll ? 1 : 0);
    }
    
    return result;
}
