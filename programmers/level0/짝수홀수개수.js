function solution(num_list) {
    const evenLen = num_list.filter(num => num % 2 == 0).length;
    return [evenLen, num_list.length - evenLen]
}
