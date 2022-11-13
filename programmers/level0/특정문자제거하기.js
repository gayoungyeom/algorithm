//my_string.split(letter).join('') 
function solution(my_string, letter) {
    const remove = [...my_string].filter(s => s !== letter).join('');
    return remove;
}
