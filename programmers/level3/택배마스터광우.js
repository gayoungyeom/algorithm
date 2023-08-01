const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [nmk, arr] = input;
const [n, m, k] = nmk.split(' ').map(Number);
arr = arr.split(' ').map(Number);

function solution(n, m, k, arr){
    const orders = [];
    let visited = [...Array(n).fill(false)];

    const permutation = (tmp) => {
        if(tmp.length === n){
            const order = [];
            for(const i of tmp){
                order.push(arr[i]);
            }
            orders.push([...order]);
            return;
        }

        for(let i = 0; i < n; i++){
            if(!visited[i]){
                tmp.push(i);
                visited[i] = true;
                permutation(tmp);
                visited[i] = false;
                tmp.pop();
            }
        }
    }

    permutation([]);

    let result = Infinity;

    for(const order of orders){
        let i = 0;
        let count = 0;
        let weight = 0;
        let totalWeight = 0;

        while(count < k){
            const curWeight = order[i];
            if(weight + curWeight <= m){
                weight += curWeight;
                i = (i + 1) % n;
            } else{
                totalWeight += weight;
                weight = 0;
                count++;
            }
        }     
        result = Math.min(result, totalWeight);
    }

    return result;
}

console.log(solution(n, m, k, arr))
