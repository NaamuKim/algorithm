const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [V, E] = input.shift().split(" ").map(Number);
const costs = input.map((str) => str.split(" ").map(Number));

// 크루스칼
// 1. 가중치 오름차순 정렬
costs.sort((a, b) => a[2] - b[2]);
const parent = Array.from({ length: V + 1 }, (_, i) => i);

function solution() {
  let answer = 0;
  function findParent(child) {
    if (parent[child] === child) return child;
    return (parent[child] = findParent(parent[child]));
  }
  function hasSameParent(a, b) {
    return findParent(a) === findParent(b);
  }
  function connect(a, b) {
    const aParent = findParent(a);
    const bParent = findParent(b);
    if (aParent !== bParent) parent[aParent] = bParent;
  }
  for (const [a, b, cost] of costs) {
    // 2. 정렬된 비용들을 돌며 부모가 다르면 비용을 더함
    if (!hasSameParent(a, b)) {
      answer += cost;
      // 3. 부모가 다르면 한 노드의 부모 노드를 다른 노드로 저장
      connect(a, b);
    }
  }
  return answer;
}

console.log(solution());
