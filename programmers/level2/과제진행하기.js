const timeToMin = (time) => {
    const [h, m] = time.split(':').map(Number);
    return h * 60 + m;
}

function solution(plans) {
    const result = [];
    
    plans = plans.map(plan => [plan[0], timeToMin(plan[1]), Number(plan[2])]);
    plans.sort((a, b) => a[1] - b[1]);
    
    const first = plans.shift();
    const stack = [first];
    let curTime = first[1];

    while (plans.length !== 0) {
        const target = plans.shift();
        const [name, start, playTime] = target;
        let diff = start - curTime;
        curTime = start;

        while (stack.length !== 0 && diff > 0) {
          const recent = stack.pop();
          const [rName, rStart, rPlayTime] = recent;

          if (rPlayTime <= diff) {
            result.push(rName);
            diff -= rPlayTime;
          } else {
            recent[2] = rPlayTime - diff;
            diff = 0;
            stack.push(recent);
          }
        }
        stack.push(target);
    }
    
    while(stack.length !== 0){
        result.push(stack.pop()[0]);
    }
    
    return result;
}


