const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [m, n, h] = input.shift().split(' ').map(Number);
const queue = [];
const dy = [0, 1, 0, -1, 0, 0];
const dx = [1, 0, -1, 0, 0, 0];
const dz = [0, 0, 0, 0, 1, -1];
let arr = [];
for (let i = 0; i < input.length; i += n) {
  arr[Math.floor(i / n)] = input.slice(i, i + n).map((item) => item.split(' ').map(Number));
}
let day = 0;
let vis = Array.from({ length: h }, () => Array.from({ length: n }, () => Array.from({ length: m }).fill(0)));

const solution = () => {
  for (let i = 0; i < h; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < m; k++) {
        if (arr[i][j][k] === 1) {
          queue.push([i, j, k]);
        }
      }
    }
  }

  bfs();
  for (let i = 0; i < h; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < m; k++) {
        if (arr[i][j][k] === 0) return -1;
        day = Math.max(vis[i][j][k], day);
      }
    }
  }
  return day;
};

const bfs = () => {
  while (queue.length) {
    const [z, y, x] = queue.shift();
    for (let k = 0; k < 6; k++) {
      const ny = y + dy[k];
      const nx = x + dx[k];
      const nz = z + dz[k];
      if (!isOnRange(ny, nx, nz) || arr[nz][ny][nx] === 1 || arr[nz][ny][nx] === -1) continue;
      arr[nz][ny][nx] = 1;
      if (vis[nz][ny][nx] === 0) vis[nz][ny][nx] = vis[z][y][x] + 1;
      else {
        vis[nz][ny][nx] = Math.min(vis[nz][ny][nx], vis[z][y][x] + 1);
      }
      queue.push([nz, ny, nx]);
    }
  }
};

const isOnRange = (y, x, z) => {
  if (y < 0 || y >= n || x < 0 || x >= m || z < 0 || z >= h) return false;
  return true;
};

console.log(solution());
