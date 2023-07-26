class PriorityQueue {
  constructor() {
    this.heap = [];
  }
    
  size() {
      return this.heap.length;
  }

  empty() {
    return this.heap.length === 0;
  }

  peek() {
    return this.heap[0];
  }

  push(data) {
    this.heap.push(data);

    let i = this.heap.length - 1;
    while (i > 0) {
      const parent = ~~((i - 1) / 2);
      if (this.heap[parent] <= this.heap[i]) break;
      [this.heap[i], this.heap[parent]] = [this.heap[parent], this.heap[i]];
      i = parent;
    }
  }

  pop() {
    if (this.empty()) return;

    const value = this.peek();
    [this.heap[0], this.heap[this.heap.length - 1]] = [
      this.heap[this.heap.length - 1],
      this.heap[0],
    ];
    this.heap.pop();
    this._heapify();
    return value;
  }

  _heapify() {
    const x = this.peek();
    const n = this.heap.length;
    let cur = 0;

    while (2 * cur + 1 < n) {
      const leftChild = 2 * cur + 1;
      const rightChild = leftChild + 1;
      const smallerChild =
        rightChild < n && this.heap[rightChild] < this.heap[leftChild]
          ? rightChild
          : leftChild;

      if (x > this.heap[smallerChild]) {
        [this.heap[cur], this.heap[smallerChild]] = [
          this.heap[smallerChild],
          this.heap[cur],
        ];
        cur = smallerChild;
      } else {
        break;
      }
    }
  }
}

function solution(scoville, K) {
    const n = scoville.length;
    const pq = new PriorityQueue();
    scoville.forEach(scov => pq.push(scov));
    
    while(pq.size() > 1){
        if(pq.peek() >= K) break;
        
        const first = pq.pop();
        const second = pq.pop();   
        const newFood = first + second * 2;
        pq.push(newFood);
    }

    const underK = Object.values(pq)[0].find(value => value < K);
    return underK ? -1 : n - pq.size();
}
