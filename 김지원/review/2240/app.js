const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [t, w] = input.shift().split(' ').map(Number);

const dp = Array.from({ length: t + 1 }, () => Array.from({ length: 2 }, () => Array.from({ length: w + 1 }).fill(-1)));

const go = (idx, pos, moveCnt) => {
  if (moveCnt < 0) return -1e9;
  if (idx === t) return moveCnt === 0 ? 0 : -1e9;
  const ret = dp[idx][pos][moveCnt];
  if (~ret) return ret;

  return (dp[idx][pos][moveCnt] =
    Math.max(go(idx + 1, pos, moveCnt), go(idx + 1, pos ^ 1, moveCnt - 1)) + Number(pos === +input[idx] - 1));
};

const solution = () => {
  return Math.max(go(0, 0, w), go(0, 1, w - 1));
};

console.log(solution());
