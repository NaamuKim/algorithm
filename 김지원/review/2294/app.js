const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [n, k] = input.shift().split(' ').map(Number);

const INF = 987654321;
const dp = Array.from({ length: 10004 }).fill(INF);
dp[0] = 0;

const solution = () => {
  for (let i = 0; i < n; i++) {
    const temp = +input[i];
    for (let j = temp; j <= k; j++) dp[j] = Math.min(dp[j], dp[j - temp] + 1);
  }
  return dp[k] === INF ? -1 : dp[k];
};

console.log(solution());
