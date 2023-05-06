const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const [F, S, G, U, D] = input.shift().split(" ").map(Number);
const q = [];
const vis = Array.from({ length: F + 1 }).fill(0);
function solution() {
  if (S === G) return 0;
  q.push(S);
  vis[S] = 1;
  while (q.length) {
    const item = +q.shift();

    for (let stair of [item + U, item - D]) {
      if (stair > F || stair < 1 || vis[stair]) continue;
      q.push(stair);
      vis[stair] = vis[item] + 1;
    }
  }
  return (vis[G] && vis[G] - 1) || "use the stairs";
}
console.log(solution());
