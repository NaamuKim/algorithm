const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const dp = input.map((item) => item.split(' ').map(Number));
const solution = () => {
  for (let i = 1; i < n; i++) {
    for (let j = 0; j < dp[i].length; j++) {
      if (j === 0 || j === dp[i].length - 1) dp[i][j] += dp[i - 1][j] || 0 + dp[i - 1][j - 1] || 0;
      else dp[i][j] += Math.max(dp[i - 1][j], dp[i - 1][j - 1]);
    }
  }
  console.log(Math.max(...dp[n - 1]));
};

solution();
