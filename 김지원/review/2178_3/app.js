const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [n, m] = input.shift().split(" ").map(Number);
const arr = input.map((item) => item.split("").map(Number));
const vis = Array.from({ length: n }, () => Array.from({ length: m }).fill(0));
const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];
function bfs() {
  const q = [];
  q.push([0, 0]);
  while (q.length) {
    const [y, x] = q[0];
    q.shift();
    if (y === n - 1 && x === m - 1) return;
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny >= n || nx >= m || ny < 0 || nx < 0 || !arr[ny][nx] || vis[ny][nx])
        continue;
      vis[ny][nx] = vis[y][x] + 1;
      q.push([ny, nx]);
    }
  }
}
bfs();
console.log(vis[n - 1][m - 1] + 1);
