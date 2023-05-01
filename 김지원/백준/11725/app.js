const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = +input.shift();
const tree = Array.from({ length: n + 1 }, () => new Array());
input.map((val) => {
  const [from, to] = val.split(" ").map(Number);
  tree[from].push(to);
  tree[to].push(from);
});
const q = [];
const vis = Array.from({ length: n + 1 }).fill(0);

function bfs() {
  q.push(1);
  vis[1] = -1;
  while (q.length) {
    const item = q.shift();
    for (let next of tree[item]) {
      if (vis[next]) continue;
      vis[next] = item;
      q.push(next);
    }
  }
}
function solution() {
  let answer = "";
  bfs();
  for (let i = 2; i <= n; i++) {
    answer += vis[i] + "\n";
  }
  console.log(answer);
}

solution();
