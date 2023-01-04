//1. 정렬 후 좌우 값과 비교
function solution(s) {
    const sorted = [...s].sort();
    const onlyOne = sorted.filter((v, i) => {
        if(i === 0) return v !== sorted[i+1];
        if(i === s.length - 1) return v !== sorted[i-1];
        return v !== sorted[i-1] && v !== sorted[i+1]
    })
    return onlyOne.join('');
}

//2. 첫 번째와 마지막 인덱스가 같다 = 값이 하나 뿐이다..!
function solution(s) {
    const onlyOne = [...s].filter(cur => s.indexOf(cur) === s.lastIndexOf(cur));
    return onlyOne.sort().join('');
}
