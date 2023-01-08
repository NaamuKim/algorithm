const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const dy = [0, 1, 0, -1, -1, -1, 1, 1];
const dx = [-1, 0, 1, 0, -1, 1, -1, 1];
let w, h, arr;

const solution = () => {
  let cnt = 0;
  [w, h] = input.shift().split(' ').map(Number);
  if (w === 0 && h === 0) {
    return;
  } else if (w === 1 && h === 1) {
    cnt = Number(input.shift());
  } else {
    arr = Array.from(Array(h), () => Array(w).fill(0));
    // 배열 채우기
    for (let i = 0; i < h; i++) {
      let tmp = input[i].split(' ').map(Number);
      arr[i] = tmp;
    }
    // 채운만큼 삭제
    input = input.slice(h);
    for (let i = 0; i < h; i++) {
      for (let j = 0; j < w; j++) {
        if (arr[i][j] === 1) {
          dfs(i, j);
          cnt += 1;
        }
      }
    }
  }
  return cnt;
};

const dfs = (i, j) => {
  if (isOnRange(i, j) && arr[i][j] === 1) {
    arr[i][j] = 0;
    for (let k = 0; k < dy.length; k++) {
      dfs(i + dx[k], j + dy[k]);
    }
  }
};

const isOnRange = (i, j) => {
  if (i < 0 || i >= h || j < 0 || j >= w) return false;
  return true;
};
while (input.length !== 0) {
  const answer = solution();
  answer !== undefined && console.log(answer);
  arr = [];
}
