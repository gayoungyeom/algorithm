function solution(s) {
    let cnt = 0;
    let zeroCnt = 0;

    while(s !== '1'){
        //0 제거
        const removed = [...s].filter(n => n === '1').join('');
        zeroCnt += (s.length - removed.length);

        //2진수로 변환
        const num = removed.length;
        s = num.toString(2);
        cnt++;
    }
    
    return [cnt, zeroCnt];
}

/*
* 진수 변환 참고
*/

//1.반복문
// let convert = [];
// while(num > 0){
//     convert.push(num % 2);
//     num = ~~(num / 2);
// }
// s = convert.reverse().join('');

//2. toString 활용 (위와 동일)
// s = num.toString(2);
