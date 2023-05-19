function processData(input) {
    input = input.toString().trim().split('\n');
    let [n, ...queries] = input;
    
    const q = [];
    for(const query of queries){
        const [type, x] = query.split(' ').map(Number);
        if(type === 1){
            q.push(x);
        } else if(type === 2){
            q.shift();
        } else if(type === 3){
            console.log(q[0]);
        }
    }
} 
