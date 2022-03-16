const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = [];
for (let i = 2; i < input.length; i++) {
  arr.push(input[i].split(' ').map((item) => +item));
}

console.log(solution(+input[0], arr));

function solution(n, arr) {
  let answer = 0;
  let graph = Array.from(Array(n + 1), () => Array(n + 1).fill(0));
  let ch = Array.from({ length: n + 1 }, () => 0);
  for (let [a, b] of arr) {
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  function DFS(v) {
    for (let i = 1; i <= n; i++) {
      if (graph[v][i] === 1 && ch[i] === 0) {
        ch[i] = 1;
        DFS(i);
      }
    }
  }
  DFS(1);
  for (let i = 2; i <= n; i++) {
    if (ch[i] === 1) {
      answer++;
    }
  }
  return answer;
}
