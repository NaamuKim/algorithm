const fs = require('fs');
const path = require('path');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [n, _, start] = input[0].split(' ').map((item) => +item);

let arr = [];

for (let i = 1; i < input.length; i++) {
  arr.push(input[i].split(' ').map((item) => +item));
}

console.log(solution(n, start, arr));

function solution(n, start, arr) {
  let answer = '';
  let graph = Array.from(Array(n + 1), () => Array(n + 1).fill(0));
  let ch = Array.from({ length: n + 1 }, () => 0);
  let ch2 = Array.from({ length: n + 1 }, () => 0);
  let path = [];
  for (let [a, b] of arr) {
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  function DFS(v) {
    ch[v] = 1;
    path.push(v);
    for (let i = 1; i <= n; i++) {
      if (graph[v][i] === 1 && ch[i] === 0) {
        DFS(i);
      }
    }
  }
  DFS(start);

  answer += path.join(' ');
  answer += '\n';
  function BFS(v) {
    let queue = [];
    queue.push(v);
    answer += v + ' ';
    while (queue.length) {
      let dequeue = queue.shift();
      ch2[dequeue] = 1;
      for (let i = 1; i < graph.length; i++) {
        if (graph[dequeue][i] === 1 && ch2[i] === 0) {
          ch2[i] = 1;
          queue.push(i);
          answer += i + ' ';
        }
      }
    }
  }
  BFS(start);
  return answer;
}
