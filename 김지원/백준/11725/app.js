const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const arr = input.map((item) => item.split(' ').map(Number));
const tree = Array.from({ length: n + 1 }, () => []);
const queue = [];
const vis = Array.from({ length: n + 1 }, () => 0);
const solution = () => {
  for (let [a, b] of arr) {
    tree[a].push(b);
    tree[b].push(a);
  }
  tree[1].forEach((item) => queue.push(item));
  vis[1];
  bfs();
  vis.slice(2).forEach((item) => console.log(item));
};

const bfs = () => {
  while (queue.length) {
    const node = queue.shift();
    for (let next of tree[node]) {
      if (!vis[next]) {
        vis[next] = node;
        queue.push(next);
      }
    }
  }
};

solution();
