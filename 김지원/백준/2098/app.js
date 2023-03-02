const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const INF = 987654321;

const n = +input.shift();
const arr = input.map((item) => item.split(' ').map(Number));
const dp = Array.from({ length: 16 }, () => Array.from({ length: 1 << 16 }).fill(-1));

const tsp = (here, visited) => {
  // 마지막 index에 접근했을 때 값이 있는지에 따라 분기 처리
  if (visited === (1 << n) - 1) return arr[here][0] ? arr[here][0] : INF;

  if (dp[here][visited] !== -1) return dp[here][visited];

  dp[here][visited] = INF;
  for (let i = 0; i < n; i++) {
    // 방문한 곳이거나 현재 idx면 continue
    if (visited & (1 << i)) continue;
    if (arr[here][i] === 0) continue;

    // 현재 위치에서 마지막 위치로 갈 때 어느 경로를 거쳐가야(깊이 우선) 최단경로인지
    dp[here][visited] = Math.min(dp[here][visited], tsp(i, visited | (1 << i)) + arr[here][i]);
  }
  return dp[here][visited];
};

const solution = () => tsp(0, 1);

console.log(solution());
