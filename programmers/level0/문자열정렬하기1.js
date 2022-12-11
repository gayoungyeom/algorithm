function solution(my_string) {
    const onlyNum = [...my_string].filter(s => (!isNaN(s)));
    return onlyNum.map(n => Number(n)).sort();
}
