const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);
const n = input.shift();
const dp = Array.from({ length: n });
const solution = () => {
  dp[0] = input[0];
  dp[1] = input[0] + input[1];
  dp[2] = Math.max(
    // 점프 or 걷기
    input[0] + input[2],
    input[1] + input[2]
  );
  for (let i = 3; i < n; i++) {
    dp[i] = Math.max(
      // 뛰 걷 걷
      dp[i - 3] + input[i - 1] + input[i],
      // 걷 뛰
      dp[i - 2] + input[i]
    );
  }
  console.log(dp[n - 1]);
};

solution();
