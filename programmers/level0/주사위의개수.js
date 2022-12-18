function solution(box, n) {
    const [width, depth, height] = box;
    return ~~(width / n) * ~~(depth / n) * ~~(height / n);
}
