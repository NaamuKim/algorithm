const fs = require('fs');
const path = require('path');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

let t = +input[0];

for (let i = 1; i <= t; i++) {
  [m, n, k] = input[1].split(' ').map((item) => +item);
  graph = Array.from(Array(m), () => Array(n).fill(0));
  for (let j = 2; j <= k + 1; j++) {
    let [x, y] = input[j].split(' ').map((item) => +item);
    graph[x][y] = 1;
  }
  console.log(solution());
  input = input.slice(k + 1);
  graph.length = 0;
}

function solution() {
  let cnt = 0;
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (graph[i][j] === 1) {
        DFS(i, j);
        cnt += 1;
      }
    }
  }
  return cnt;
}

function DFS(x, y) {
  let dx = [0, 1, 0, -1];
  let dy = [1, 0, -1, 0];
  if (RangeCheck(x, y)) {
    if (graph[x][y] === 1) {
      graph[x][y] = 0;
      for (let k = 0; k <= 3; k++) {
        DFS(x + dx[k], y + dy[k]);
      }
    }
  } else return;
}

function RangeCheck(i, j) {
  if (i >= 0 && i < m && j >= 0 && j < n) {
    return true;
  } else return false;
}
