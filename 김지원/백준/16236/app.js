const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

// const coorArr = Array.from({ length: 7 }, () => new Array());
let q = [];
const n = +input.shift();
let answer = 0;
let vis = Array.from({ length: n }, () => Array.from({ length: n }).fill(0));

const babyShark = {
  size: 2,
  remainFoodToLevelUp: 2,
  eat() {
    this.remainFoodToLevelUp--;
    if (this.remainFoodToLevelUp === 0) {
      this.size += 1;
      this.remainFoodToLevelUp = this.size;
    }
  },
  initialValue: { y: null, x: null },
};
const arr = input.map((item, y) =>
  item.split(" ").map((val, x) => {
    const res = Number(val);
    if (res === 9) {
      babyShark.initialValue.y = y;
      babyShark.initialValue.x = x;
      q.push({ y, x });
      return 0;
    }
    return res;
  })
);

const dy = [-1, 0, 0, 1];
const dx = [0, -1, 1, 0];

function bfs() {
  while (q.length) {
    const { y, x } = q.shift();
    if (
      q.findIndex(
        ({ y, x }) => arr[y][x] < babyShark.size && arr[y][x] >= 1
      ) !== -1
    ) {
      q.sort((a, b) => {
        if (a.y === b.y) return a.x - b.x;
        return a.y - b.y;
      });
      q.sort((a, b) => vis[a.y][a.x] - vis[b.y][b.x]);
    }
    if (arr[y][x] >= 1 && arr[y][x] < babyShark.size) {
      babyShark.eat();
      answer += vis[y][x];
      vis = Array.from({ length: n }, () => Array.from({ length: n }).fill(0));
      arr[y][x] = 0;
      q = [];
    }
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (
        ny < 0 ||
        ny >= n ||
        nx < 0 ||
        nx >= n ||
        vis[ny][nx] ||
        arr[ny][nx] > babyShark.size
      )
        continue;
      vis[ny][nx] = vis[y][x] + 1;
      q.push({ y: ny, x: nx });
    }
  }
}

//dfs(babyShark.initialValue.y, babyShark.initialValue.x);
bfs();
console.log(answer);
