const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = +input.shift();
const M = +input.shift();
const [start, end] = input.pop().split(" ").map(Number);
const graph = Array.from({ length: N + 1 }, () =>
  Array.from({ length: N + 1 }).fill(0)
);

const arr = input.map((str) => {
  const arr = str.split(" ");
  graph[+arr[0]][+arr[+1]] = +arr[+2];
  return arr.map(Number);
});
arr.sort((a, b) => a[2] - b[2]);

function solution() {
  let answer = 0;
  const parents = Array.from({ length: N + 1 }, (_, idx) => idx);
  function find(child) {
    if (parents[child] === child) return child;
    return (parents[child] = find(parents[child]));
  }
  function union(a, b) {
    a = find(a);
    b = find(b);
    if (a !== b) {
      parents[b] = a;
    }
  }
  function hasSameParent(a, b) {
    a = find(a);
    b = find(b);
    return a === b;
  }
  arr.forEach(([a, b, cost]) => {
    if (!hasSameParent(a, b)) {
      answer += cost;
      union(a, b);
    }
  });
  return answer;
}
console.log(solution());
