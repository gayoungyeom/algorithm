//1. filter
function solution(s){
    const lowerCase = [...s.toLowerCase()];
    return lowerCase.filter(v => v === "p").length === lowerCase.filter(v => v === "y").length;
}

//2. split
function solution(s){
    const lowerCase = s.toLowerCase();
    return lowerCase.split("p").length === lowerCase.split("y").length;
}
