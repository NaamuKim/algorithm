const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = +input.shift();
const [start, end] = input.shift().split(" ").map(Number);
const m = +input.shift();
const arr = Array.from({ length: n + 1 }, () => new Array());
const vis = Array.from({ length: n + 1 }).fill(0);
input
  .map((item) => item.split(" ").map(Number))
  .forEach(([x, y]) => {
    arr[y].push(x);
    arr[x].push(y);
  });

const bfs = () => {
  const q = [];
  q.push(start);
  vis[start] = 1;
  while (q.length) {
    const item = q.pop();
    for (let next of arr[item]) {
      if (vis[next]) continue;
      q.push(next);
      vis[next] = vis[item] + 1;
    }
  }
};

bfs();

console.log(vis[end] - 1 || -1);
