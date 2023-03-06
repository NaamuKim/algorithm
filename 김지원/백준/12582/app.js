const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = +input[0];
const INF = 987654321;
const dp = Array.from({ length: 1000004 }).fill(INF);
let ret = '';
const go = (here) => {
  if (here === 0) return;
  ret += here + ' ';
  if (here % 3 === 0 && dp[here] === dp[here / 3] + 1) go(here / 3);
  else if (here % 2 == 0 && dp[here] == dp[here / 2] + 1) go(here / 2);
  else if (here - 1 >= 0 && dp[here] == dp[here - 1] + 1) go(here - 1);
  return;
};

const solution = () => {
  dp[1] = 0;
  for (let i = 1; i <= n; i++) {
    if (!(i % 3)) dp[i] = Math.min(dp[i / 3] + 1, dp[i]);
    if (!(i % 2)) dp[i] = Math.min(dp[i / 2] + 1, dp[i]);
    dp[i] = Math.min(dp[i - 1] + 1, dp[i]);
  }
  console.log(dp[n]);
  go(n);
  console.log(ret);
};

solution();
