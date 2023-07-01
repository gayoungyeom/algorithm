const time2Min = (time) => { //"14:20"을 분으로 바꿈
    const [h, m] = time.split(':').map(Number);
    return h * 60 + m;
}

function solution(book_time) {
    //시작 시각 기준으로 정렬
    book_time.sort((a, b) => a[0].split(':').join('') - b[0].split(':').join(''));
    
    const rooms = [book_time[0]];
    
    //배열에 있는 시간 중 마지막 시간 + 10 <= 현재 시작 시각이면 교체 (&& 텀이 가장 작은 방)
    for(let i = 1; i < book_time.length; i++){
        const [start, end] = book_time[i];
        
        let idx = 0;
        let min = Infinity;
        let flag = true; //방을 추가해야 하는지 판단하는 플래그
        for(let j = 0; j < rooms.length; j++){
            const gap = time2Min(start) - (time2Min(rooms[j][1]) + 10);
            if(gap >= 0){
                if(gap < min){
                    idx = j;
                    min = gap;
                }
                flag = false;
            }
        }
        
        if(flag){
            rooms.push(book_time[i]);
        } else{
            rooms.splice(idx, 1, book_time[i]);
        }
    }
    
    console.log(rooms);
    return rooms.length;
}
