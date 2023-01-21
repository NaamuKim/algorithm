const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = input.shift();
const rgb = input.map((item) => item.split(' ').map(Number));
const dp = Array.from({ length: n + 1 }, () => Array.from({ length: 3 }).fill(0));

const solution = () => {
  dp[1] = rgb[0];
  for (let i = 2; i <= n; i++) {
    dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + rgb[i - 1][0];
    dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + rgb[i - 1][1];
    dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + rgb[i - 1][2];
  }
  console.log(Math.min(...dp[n]));
};

solution();
