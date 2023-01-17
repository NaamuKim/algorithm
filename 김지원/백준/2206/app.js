const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const [n, m] = input.shift().split(' ').map(Number);
const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];
const arr = input.map((item) => item.split('').map(Number));
const walls = [];
walls.push([0, 0]);
arr.forEach((item, i) => item.forEach((item2, j) => item2 === 1 && walls.push([i, j])));
const queue = [];
let vis = [];
let min = 987654321;
const solution = () => {
  walls.forEach(([y, x]) => {
    vis = Array.from({ length: n + 1 }, () => Array.from({ length: m }).fill(0));
    arr[y][x] = 0;
    queue.push([0, 0]);
    bfs();
    // console.log(vis);
    if (vis[n - 1][m - 1] !== 0) min = Math.min(min, vis[n - 1][m - 1]);
    arr[y][x] = 1;
  });

  console.log(min === 987654321 ? -1 : min + 1);
};

const bfs = () => {
  while (queue.length) {
    const [y, x] = queue.shift();
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] === 1 || vis[ny][nx] >= 1) continue;
      vis[ny][nx] = vis[ny][nx] < vis[y][x] + 1 && vis[y][x] + 1;
      queue.push([ny, nx]);
    }
  }
};

solution();
