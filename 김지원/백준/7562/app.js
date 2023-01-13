const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const t = +input.shift();

class Node {
  constructor(x, y) {
    this.prev = null;
    this.next = null;
    this.x = x;
    this.y = y;
  }
}
class Queue {
  constructor() {
    this.front = null;
    this.rear = null;
    this.size = 0;
  }

  enqueue(x, y) {
    const node = new Node(x, y);
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

let queue = new Queue();
let vis, n;
const dy = [1, 1, -1, -1, 2, 2, -2, -2];
const dx = [2, -2, 2, -2, 1, -1, 1, -1];

const solution = () => {
  for (let i = 0; i < input.length; i += 3) {
    const [a, b, c] = input.slice(i, i + 3);
    n = +a;
    vis = Array.from({ length: n }, () => Array.from({ length: n }).fill(0));
    const [sy, sx] = b.split(' ').map(Number);
    const [ey, ex] = c.split(' ').map(Number);
    if (sy === ey && sx === ex) {
      console.log(0);
      continue;
    }
    queue.enqueue(sx, sy);
    bfs(ey, ex);
    console.log(vis[ey][ex]);
  }
};

const bfs = (ey, ex) => {
  while (queue.size) {
    const { y, x } = queue.dequeue();
    for (let k = 0; k < 8; k++) {
      const ny = y + dy[k];
      const nx = x + dx[k];
      if (!isOnRange(ny, nx)) continue;
      queue.enqueue(nx, ny);
      vis[ny][nx] = vis[ny][nx] === 0 ? vis[y][x] + 1 : Math.min(vis[ny][nx], vis[y][x] + 1);
      if (ny === ey && nx === ex) {
        queue = new Queue();
        return;
      }
    }
  }
};

const isOnRange = (y, x) => {
  if (y < 0 || y >= n || x < 0 || x >= n || vis[y][x] !== 0) return false;
  return true;
};

solution();
