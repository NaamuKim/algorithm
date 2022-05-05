const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
let t = +input[0];
const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

for (let i = 1; i <= t; i++) {
  [m, n, k] = input[1].split(' ').map((item) => +item);
  graph = Array.from(Array(n), () => Array(m).fill(0));
  vis = Array.from(Array(n), () => Array(m).fill(0));
  for (let j = 2; j <= k + 1; j++) {
    let [x, y] = input[j].split(' ').map((item) => +item);
    graph[y][x] = 1;
  }
  console.log(solution());
  input = input.slice(k + 1);
  graph.length = 0;
  vis.length = 0;
}

function solution() {
  let cnt = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (!vis[i][j] && graph[i][j] === 1) {
        cnt++;
        dfs(i, j);
      }
    }
  }
  function dfs(y, x) {
    vis[y][x] = 1;
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || vis[ny][nx]) continue;
      if (graph[ny][nx] === 1) {
        dfs(ny, nx);
      }
    }
  }
  return cnt;
}
