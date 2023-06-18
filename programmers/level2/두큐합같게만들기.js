class Node {
  constructor(data){  
    this.data = data;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }

  isEmpty() {
    return this.size === 0;
  }

  enqueue(data) {
    const newNode = new Node(data);
    if(this.isEmpty()) this.front = newNode;
    else this.rear.next = newNode;
    this.rear = newNode;
    this.size++;
  }

  dequeue() {
    if(this.isEmpty()) return;
    const data = this.front.data;
    this.front = this.front.next;
    this.size--;
    return data;
  }
}

//1. Queue 풀이
function solution(queue1, queue2) {
    const n = queue1.length;
    const q1 = new Queue();
    const q2 = new Queue();
    for(let i = 0; i < n; i++){
        q1.enqueue(queue1[i]);
        q2.enqueue(queue2[i]);
    }
    
    let count = 0;
    let sum1 = queue1.reduce((a, b) => a + b);
    let sum2 = queue2.reduce((a, b) => a + b);
    
    if((sum1 + sum2) % 2 !== 0) return -1;
    while(sum1 !== sum2) {
        if(count > 2 * n) {
            count = -1;
            break;
        }
        
        if(sum1 < sum2) {
            const value = q2.dequeue();
            q1.enqueue(value);
            sum1 += value;
            sum2 -= value;
        } else {
            const value = q1.dequeue();
            q2.enqueue(value);
            sum2 += value;
            sum1 -= value;
        }
        
        count++;
    }
    
    return count;
}

//2. shift 없이 풀이
function solution(queue1, queue2) {
    let count = 0;
    let i = 0, j = 0;
    let sum1 = queue1.reduce((a, b) => a + b);
    let sum2 = queue2.reduce((a, b) => a + b);
    const maxLoop = queue1.length * 2;
    
    while(sum1 !== sum2) {
        if(count > maxLoop + 1) {
            count = -1;
            break;
        }
        
        if(sum1 < sum2) {
            const value = queue2[j++];
            queue1.push(value);
            sum1 += value;
            sum2 -= value;
        } else {
            const value = queue1[i++];
            queue2.push(value);
            sum2 += value;
            sum1 -= value;
        }
        
        count++;
    }
    
    return count;
}
