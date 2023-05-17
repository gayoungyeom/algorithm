const MAX = 100;
function countingSort(arr) {
    let count = [...Array(MAX).fill(0)];
    for(const num of arr){
        count[num]++;
    }
    return count;
}
