const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const arr = input[0].split(' ').map(Number);
const dp = Array.from(n).fill(0);

const solution = () => {
  let res = arr[0];
  dp[0] = arr[0];
  for (let i = 1; i < n; i++) {
    // 10 10 10 10 15 21 21 21
    dp[i] = Math.max(dp[i - 1] + arr[i], arr[i]);
    res = Math.max(dp[i], res);
  }
  console.log(res);
};

solution();
