const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [M, N] = input.shift().split(' ').map(Number);

const arr = input.map((item) => item.split(' ').map(Number));

const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];
const dp = Array.from({ length: M }, () => Array.from({ length: N }).fill(-1));
dp[M - 1][N - 1] = 1;

function solution() {
  return bfs(0, 0);
}
function bfs(y, x) {
  if (dp[y][x] !== -1) return dp[y][x];

  let count = 0;
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (ny < 0 || ny >= M || nx < 0 || nx >= N || arr[ny][nx] >= arr[y][x]) continue;
    count += bfs(ny, nx);
  }
  dp[y][x] = count;
  return count;
}
console.log(solution());
