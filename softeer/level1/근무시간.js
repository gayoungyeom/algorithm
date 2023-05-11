const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let timeList = input.map(v => v.split(' '));


let workTime = 0;

for(let i = 0; i < timeList.length; i++){
    const [start, end] = timeList[i];
    const [startH, startM] = start.split(':').map(Number);
    const [endH, endM] = end.split(':').map(Number);

    let diffH = endH - startH;
    let diffM = endM - startM;

    if(endM < startM){
        diffH--;
        diffM = 60 - startM + endM;
    }

    const today = diffH * 60 + diffM;
    workTime += today;
}

console.log(workTime);
