const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [t, w] = input.shift().split(' ').map(Number);
// 3차원 배열 [나무][어떤 나무][이동]
const dp = Array.from({ length: 1004 }, () => Array.from({ length: 2 }, () => Array.from({ length: 34 }).fill(-1)));

const go = (idx, tree, cnt) => {
  if (cnt < 0) return -1e9;
  if (idx === t) return cnt == 0 ? 0 : -1e9;

  const ret = dp[idx][tree][cnt];
  if (ret !== -1) return ret;

  // 움직이거나 안 움직이는 것
  return (dp[idx][tree][cnt] =
    Math.max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + Number(tree == +input[idx] - 1));
};

const solution = () => {
  return Math.max(go(0, 1, w - 1), go(0, 0, w));
};

console.log(solution());
