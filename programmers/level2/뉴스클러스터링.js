const splitTwoChar = (str) => {
    const arr = [];
    for(let i = 0; i < str.length - 1; i++){
        const s = str.slice(i, i + 2);
        if(!s.match(/[^a-zA-Z]/g)){
            arr.push(s.toUpperCase());   
        }
    }
    return arr;
}

const getIntersection = (arr1, arr2) => {
    const intersection = [];
    
    let checked1 = [...Array(arr1.length).fill(false)];
    let checked2 = [...Array(arr2.length).fill(false)];
    
    for(let i = 0; i < arr1.length; i++){
        for(let j = 0; j < arr2.length; j++){
            if(!checked1[i] && !checked2[j] && arr1[i] === arr2[j]){
                intersection.push(arr1[i]);
                checked1[i] = true;
                checked2[j] = true;
            }      
        }
    }    
    
    return intersection;
}

const MUL = 65536;

function solution(str1, str2) {
    const arr1 = splitTwoChar(str1);
    const arr2 = splitTwoChar(str2);
    
    if(arr1.length === 0 && arr2.length === 0) return MUL;
    
    const intersection = getIntersection(arr1, arr2).length;
    const union = arr1.length + arr2.length - intersection;
   
    return parseInt((intersection / union * MUL));
}
