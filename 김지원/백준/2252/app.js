const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [N, M] = input.shift().split(" ").map(Number);
const arr = input.map((str) => str.split(" ").map(Number));
const q = [];
const graph = Array.from({ length: N + 1 }, () => new Array());
const in_degree = Array.from({ length: N + 1 }).fill(0);

function solution() {
  const result = [];
  arr.forEach(([prev, next]) => {
    graph[prev].push(next);
    in_degree[next]++;
  });
  for (let i = 1; i <= N; i++) {
    if (!in_degree[i]) q.push(i);
  }
  while (q.length) {
    const item = q.shift();
    result.push(item);
    for (let next of graph[item]) {
      in_degree[next] -= 1;
      if (!in_degree[next]) {
        q.push(next);
      }
    }
  }
  return result.join(" ");
}
console.log(solution());
