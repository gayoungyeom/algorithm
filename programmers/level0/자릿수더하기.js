function solution(n) {
    const str = String(n); //number to string
    const arr = str.split(''); //string to array
    const sum = arr.reduce((acc, cur) => acc + Number(cur), 0);
    return sum;
}
