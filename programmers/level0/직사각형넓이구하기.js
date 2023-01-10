function solution(dots) {
    dots.sort();
    
    const x = Math.abs(dots[2][0] - dots[0][0]);
    const y = Math.abs(dots[1][1] - dots[0][1]);
    return x * y;
}
