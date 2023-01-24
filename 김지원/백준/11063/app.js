const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const arr = input[0].split(' ').map(Number);
const dp = Array.from({ length: n }).fill(0);
const solution = () => {
  for (let i = 0; i < n; i++) {
    let max = 0;
    for (let j = 0; j < i; j++) {
      if (arr[i] > arr[j] && dp[j] > max) max = dp[j];
    }
    dp[i] = max + 1;
  }
  console.log(Math.max(...dp));
};

solution();
