const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);
const n = +input.shift();

const solution = () => {
  const res = [];
  input.forEach((item) => {
    const dp = Array.from(100).fill(0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for (let i = 3; i < item; i++) {
      dp[i] = dp[i - 3] + dp[i - 2];
    }
    res.push(dp[item - 1]);
  });

  console.log(res.join('\n'));
};

solution();
