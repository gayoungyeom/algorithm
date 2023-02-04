const str = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];

//1. 정규식
function solution(s) {
    for(let i = 0; i < str.length; i++){
        const regex = new RegExp(`${str[i]}`, 'ig');
        s = s.replaceAll(regex, i)
    }
    return +s;
}

//2. split
function solution(s) {
    for(let i = 0; i < str.length; i++){
        s = s.split(str[i]).join(i);
    }
    return +s;
}
