const getGradient = (x, y) => (y[1] - x[1]) / (y[0] - x[0]);

function solution(dots) {
    const [d1, d2, d3, d4] = dots;

    const c1 = getGradient(d1, d2) === getGradient(d3, d4);
    const c2 = getGradient(d1, d3) === getGradient(d2, d4);
    const c3 = getGradient(d1, d4) === getGradient(d2, d3);

    return c1 || c2 || c3 ? 1 : 0;
}
