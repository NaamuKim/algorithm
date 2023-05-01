const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = +input.shift();
const [a, b] = input.shift().split(" ").map(Number);
const m = +input.shift();
const rel = input.map((item) => item.split(" ").map(Number));
const arr = Array.from({ length: n + 1 }, () =>
  Array.from({ length: n + 1 }).fill(0)
);
const vis = Array.from({ length: n + 1 }).fill(0);

function bfs(q) {
  while (q.length) {
    const item = q.shift();
    for (let i = 1; i <= n; i++) {
      if (arr[item][i] && !vis[i]) {
        q.push(i);
        vis[i] = vis[item] + 1;
      }
    }
  }
}

function solution() {
  rel.forEach(([y, x]) => {
    arr[y][x] = 1;
    arr[x][y] = 1;
  });

  const q = [];
  q.push(a);
  bfs(q);
  return vis[b] || -1;
}

console.log(solution());
