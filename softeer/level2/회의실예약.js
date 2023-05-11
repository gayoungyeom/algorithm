const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let [nm, ...rest] = input;
let [n, m] = nm.split(' ').map(Number);

const rooms = [];
for(let i = 0; i < n; i++){
    rooms.push(rest[i]);
}

const reserved = [];
for(let i = n; i < n + m; i++){
    reserved.push(rest[i]);
}

//풀이
const TIME = 10; //9 to 18
let roomsObj = {};
rooms.sort();
for(let i = 0; i < n; i++){
    //9 ~ 18시 해당 회의실 사용 가능 여부를 체크하는 배열
    roomsObj[rooms[i]] = [...Array(TIME).fill(0)];
    roomsObj[rooms[i]][9] = 1;
}

for(let i = 0; i < m; i++){
    let [r, s, t] = reserved[i].split(' ');
    s = +s - 9;
    t = +t - 9;
    for(let j = s; j < t; j++){
        roomsObj[r][j] = 1;
    }
}

let result = '';

for(let i = 0; i < n; i++){
    result += `Room ${rooms[i]}:\n`;
    
    let cnt = 0;
    let start = 0;
    let available = '';
    for(let j = 1; j < TIME; j++){
        if(roomsObj[rooms[i]][j - 1] === 0 && roomsObj[rooms[i]][j] === 1){
            cnt++; 
            available += `${(start + 9).toString().padStart(2, '0')}-${(j + 9).toString().padStart(2, '0')}\n`;  
        } else if(roomsObj[rooms[i]][j - 1] === 1 && roomsObj[rooms[i]][j] === 0){
            start = j;
        }
    }

    if(available){
        result += `${cnt} available:\n`;
        result += `${available}`;
    } else{
        result += `Not available\n`;
    }
    if(i !== (n - 1)) result += `-----\n`;
}

console.log(result);
