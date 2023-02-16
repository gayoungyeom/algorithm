const LEFT = [1, 4, 7];
const RIGHT = [3, 6, 9];
const LOC = {
    1: [0, 0], 2: [0, 1], 3: [0, 2],
    4: [1, 0], 5: [1, 1], 6: [1, 2],
    7: [2, 0], 8: [2, 1], 9: [2, 2],
    '*': [3, 0], 0: [3, 1], '#': [3, 2],
}

let curL = '*';
let curR = '#';

const useHand = (h, number) => {
    if(h === 'R'){
        curR = number;
        return 'R';        
    }
    curL = number;
    return 'L';   
}

function solution(numbers, hand) {
    return numbers.map(number => {
        if(LEFT.includes(number)) return useHand('L', number);
        if(RIGHT.includes(number)) return useHand('R', number);
        
        const [x, y] = LOC[number];
        const [lx, ly] = LOC[curL];
        const [rx, ry] = LOC[curR];
        const distL = Math.abs(x - lx) + Math.abs(y - ly);
        const distR = Math.abs(x - rx) + Math.abs(y - ry);
        
        if(distL === distR) {
            if(hand === 'right') return useHand('R', number);
            return useHand('L', number);
        }
        
        if(distL > distR) return useHand('R', number);
        return useHand('L', number);
    }).join('');
}
