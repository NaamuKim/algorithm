const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [m, n, h] = input.shift().split(' ').map(Number);

class Node {
  constructor(x, y, z, count) {
    this.prev = null;
    this.next = null;
    this.x = x;
    this.y = y;
    this.z = z;
    this.count = count;
  }
}
class Queue {
  constructor() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }
  enqueue(x, y, z, count) {
    const node = new Node(x, y, z, count);
    if (!this.size) {
      this.front = node;
      this.rear = node;
    } else {
      this.rear.next = node;
      node.prev = this.rear;
      this.rear = node;
    }
    this.size++;
  }
  dequeue() {
    const node = this.front;
    if (this.size === 1) {
      this.front = null;
      this.rear = null;
    } else {
      this.front = node.next;
      this.front.prev = null;
    }
    this.size--;
    return node;
  }
}
const queue = new Queue();
const dy = [0, 1, 0, -1, 0, 0];
const dx = [1, 0, -1, 0, 0, 0];
const dz = [0, 0, 0, 0, 1, -1];
let arr = [];
for (let i = 0; i < input.length; i += n) {
  arr[Math.floor(i / n)] = input.slice(i, i + n).map((item) => item.split(' ').map(Number));
}
let zero = false,
  zeroCount = 0;
answer = 0;

const solution = () => {
  for (let i = 0; i < h; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < m; k++) {
        if (arr[i][j][k] === 1) {
          queue.enqueue(k, j, i, 0);
        } else if (arr[i][j][k] === 0) {
          zeroCount++;
          zero = true;
        }
      }
    }
  }
  if (!zero) return answer;
  bfs();

  return zeroCount ? -1 : answer;
};

const bfs = () => {
  while (queue.size) {
    const { z, y, x, count } = queue.dequeue();
    for (let k = 0; k < 6; k++) {
      const ny = y + dy[k];
      const nx = x + dx[k];
      const nz = z + dz[k];
      if (!isOnRange(ny, nx, nz) || arr[nz][ny][nx] === 1 || arr[nz][ny][nx] === -1) continue;
      arr[nz][ny][nx] = 1;
      zeroCount--;
      queue.enqueue(nx, ny, nz, count + 1);
      answer = Math.max(answer, count + 1);
    }
  }
};

const isOnRange = (y, x, z) => {
  if (y < 0 || y >= n || x < 0 || x >= m || z < 0 || z >= h) return false;
  return true;
};

console.log(solution());
