const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);
const n = +input.shift();

const solution = () => {
  const dp = Array.from({ length: n }).fill(0);
  if (n === 1) return input[0];
  if (n === 2) return input[0] + input[1];
  dp[1] = input[0];
  dp[2] = input[0] + input[1];
  for (let i = 3; i <= n; i++) {
    dp[i] = Math.max(dp[i - 3] + input[i - 2] + input[i - 1], dp[i - 2] + input[i - 1], dp[i - 1]);
  }
  return dp[n];
};

console.log(solution());
