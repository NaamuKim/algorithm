const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = +input.shift();

const arr = input.map((str) => str.split(' ').map(Number));
const INF = 987654321;

// dp[here][vis] vis 는 조합
const dp = Array.from({ length: 16 }, () => Array.from({ length: 1 << 16 }).fill(-1));

const tsp = (here, visited) => {
  if (visited === (1 << n) - 1) return arr[here][0] ? arr[here][0] : INF;
  if (dp[here][visited] !== -1) return INF;

  dp[here][visited] = INF;

  for (let i = 0; i < n; i++) {
    if (visited & (1 << i)) continue;
    if (arr[here][i] === 0) continue;

    dp[here][visited] = Math.min(dp[here][visited], tsp(i, visited | (1 << i)) + arr[here][i]);
  }
  console.log(here, visited, dp[0][1]);
  return dp[here][visited];
};

const solution = () => tsp(0, 1);

console.log(solution());
