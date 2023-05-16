function plusMinus(arr) {
    const n = arr.length;
    
    const positive = arr.filter(v => v > 0).length;
    const negative = arr.filter(v => v < 0).length;
    const zero = n - positive - negative;
    
    console.log(positive / n);
    console.log(negative / n);
    console.log(zero / n);
}
