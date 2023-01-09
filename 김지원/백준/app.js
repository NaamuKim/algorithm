const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];
const arr = input.map((item) => item.split(''));
let vis = Array.from({ length: n }, () => Array.from({ length: n }).fill(0));

const solution = () => {
  let cnt1 = 0,
    cnt2 = 0;
  console.log(n);
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (!vis[i][j]) {
        dfs(i, j, arr[i][j]);
        cnt1++;
      }
    }
  }
  vis = Array.from({ length: n }, () => Array.from({ length: n }).fill(0));
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (!vis[i][j]) {
        dfs2(i, j, arr[i][j]);
        cnt2++;
      }
    }
  }
  return cnt1 + ' ' + cnt2;
};

const dfs = (y, x, item) => {
  for (let k = 0; k < dy.length; k++) {
    const ny = y + dy[k];
    const nx = x + dx[k];
    if (isOnRange(ny, nx) && arr[ny][nx] === item) {
      vis[ny][nx] = 1;
      dfs(ny, nx, arr[ny][nx]);
    }
  }
};

const dfs2 = (y, x, item) => {
  for (let k = 0; k < dy.length; k++) {
    const ny = y + dy[k];
    const nx = x + dx[k];
    if (isOnRange(ny, nx) && isSameColor(item, arr[ny][nx])) {
      vis[ny][nx] = 1;
      dfs2(ny, nx, arr[ny][nx]);
    }
  }
};

const isSameColor = (now, next) => {
  if (now === 'R' && next === 'G') return true;
  if (now === 'G' && next === 'R') return true;
  if (now === next) return true;
  return false;
};

const isOnRange = (i, j) => {
  if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] === 1) return false;
  return true;
};

console.log(solution());
