function solution(name, yearning, photo) {
    const result = [];
    for(let i = 0; i < photo.length; i++){
        let sum = 0;
        for(let j = 0; j < photo[i].length; j++){
            const person = photo[i][j];
            const idx = name.findIndex(n => n === person);
            sum += (yearning[idx] || 0);
        }
        result.push(sum);
    }
    return result;
}
