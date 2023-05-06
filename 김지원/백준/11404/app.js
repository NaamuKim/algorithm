const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = +input.shift();
const m = +input.shift();
const arr = Array.from({ length: n + 1 }, () =>
  Array.from({ length: n + 1 }).fill(Infinity)
);
for (let i = 1; i <= n; i++) {
  arr[i][i] = 0;
}

input.forEach((str) => {
  const [a, b, c] = str.split(" ").map(Number);
  if (arr[a][b]) {
    arr[a][b] = Math.min(c, arr[a][b]);
    return;
  }
  arr[a][b] = c;
});
function floyd() {
  for (let m = 1; m <= n; m++) {
    for (let s = 1; s <= n; s++) {
      for (let e = 1; e <= n; e++) {
        if (arr[s][e] > arr[s][m] + arr[m][e])
          arr[s][e] = arr[s][m] + arr[m][e];
      }
    }
  }
}

function solution() {
  floyd();
  let ret = "";
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      ret += (arr[i][j] !== Infinity ? arr[i][j] : 0) + " ";
    }
    ret += "\n";
  }
  return ret;
}

console.log(solution());
