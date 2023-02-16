const POINTS = { 1: 3, 2: 2, 3: 1, 4: 0, 5: 1, 6: 2, 7: 3 };

const types = { R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0 };

const findMaxType = (a, b) => {
    if(types[a] === types[b]) return [a, b].sort()[0];
    if(types[a] > types[b]) return a;
    return b;
}

function solution(survey, choices) {    
    survey.forEach((s, i) => types[s[choices[i] < 4 ? 0 : 1]] += POINTS[choices[i]]);    
    return findMaxType('R', 'T') + findMaxType('C', 'F') + findMaxType('J', 'M') + findMaxType('A', 'N');
}
