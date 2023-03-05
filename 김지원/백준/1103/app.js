const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [n, m] = input.shift().split(' ').map(Number);
const arr = input.map((str) => [0, ...str.split('')]);
arr.unshift(0);

const vis = Array.from({ length: n + 1 }, () => Array.from({ length: m + 1 }).fill(false));

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

const dp = Array.from({ length: 54 }, () => Array.from({ length: 54 }).fill(0));

const isIn = (y, x) => 1 <= y && y <= n && 1 <= x && x <= m;
const go = (y, x) => {
  if (!isIn(y, x) || arr[y][x] === 'H') return 0;
  if (vis[y][x]) {
    console.log(-1);
    process.exit();
  }
  if (dp[y][x]) return dp[y][x];

  vis[y][x] = true;
  const val = arr[y][x];

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i] * val;
    const nx = x + dx[i] * val;
    dp[y][x] = Math.max(dp[y][x], go(ny, nx) + 1);
  }
  vis[y][x] = false;
  return dp[y][x];
};

const solution = () => go(1, 1);
console.log(solution());
