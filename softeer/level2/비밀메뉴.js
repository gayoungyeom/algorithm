const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [nmk, secretMenus, buttons] = input;
const [n, m, k] = nmk.split(' ').map(Number);
secretMenus = secretMenus.split(' ').map(Number);
buttons = buttons.split(' ').map(Number);

function solution(n, m, k, secretMenus, buttons){
    let isSecret = false;
    for(let i = 0; i < buttons.length - secretMenus.length + 1; i++){
        const button = buttons.slice(i, i + secretMenus.length).join('');
        if(secretMenus.join('').includes(button)){
            isSecret = true;
            break;
        }
    }
    return isSecret ? 'secret' : 'normal';
}

console.log(solution(n, m, k, secretMenus, buttons));
