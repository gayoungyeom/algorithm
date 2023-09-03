function solution(n, works) {
    const sum = works.reduce((a, b) => a + b);
    if(sum <= n) return 0;
    
    works.sort((a, b) => b - a);
    while(n > 0){
        const max = works[0];
        for(let i = 0; i < works.length; i++){ //최대값 한번에 처리
            if(works[i] >= max){
                works[i]--;
                n--;
            }
            if(n === 0) break;
        }
    }
    
    const result = works.map(work => work**2);
    return result.reduce((a, b) => a + b);
}

//효율성 테스트 FAIL
// function solution(n, works) {
//     const sum = works.reduce((a, b) => a + b);
//     if(sum <= n) return 0;
    
//     while(n > 0){
//         works.sort((a, b) => b - a);
//         works[0]--;
//         n--;
//     }
    
//     const result = works.map(work => work**2);
//     return result.reduce((a, b) => a + b);
// }
