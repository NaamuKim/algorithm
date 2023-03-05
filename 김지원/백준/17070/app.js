const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = +input.shift();
const arr = Array.from({ length: 24 }, () => Array.from({ length: 24 }).fill(0));
const dp = Array.from({ length: 24 }, () => Array.from({ length: 24 }, () => Array.from({ length: 3 }).fill(0)));

input.forEach((strArr, i) =>
  strArr
    .split(' ')
    .map(Number)
    .forEach((data, j) => (arr[i + 1][j + 1] = data))
);
const check = (y, x, pos) => {
  if (pos === 0 || pos === 2) {
    if (!arr[y][x]) return true;
  } else if (pos === 1) {
    if (arr[y][x] === 0 && arr[y - 1][x] === 0 && arr[y][x - 1] === 0) return true;
  }
  return false;
};

const solution = () => {
  dp[1][2][0] = 1;
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
      if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

      if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
      if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

      if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
      if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
      if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
    }
  }
  return dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
};

console.log(solution());
