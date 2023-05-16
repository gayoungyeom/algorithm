function miniMaxSum(arr) {
    arr.sort((a, b) => a - b);
    const sum = arr.reduce((a, b) => a + b, 0);
    const min = sum - arr[arr.length - 1];
    const max = sum - arr[0];
    console.log(min, max);
}
