const fs = require('fs');
const path = require('path');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const n = Number(input[0].slice());

let arr = [];

for (let i = 1; i < input.length; i++) {
  arr.push(input[i].split('').map((item) => +item));
}

console.log(solution(n, arr));

function solution(n, arr) {
  let answer = [];
  let home = 0;
  let dx = [-1, 0, 1, 0];
  let dy = [0, 1, 0, -1];

  const rangeCheck = (i, j) => {
    if (i >= 0 && i < n && j >= 0 && j < n) {
      return true;
    } else return false;
  };

  function DFS(i, j) {
    if (rangeCheck(i, j) && arr[i][j] === 1) {
      arr[i][j] = 0;
      home += 1;
      for (let k = 0; k <= 3; k++) {
        DFS(i + dx[k], j + dy[k]);
      }
    }
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (arr[i][j] === 1) {
        DFS(i, j);
        answer.push(home);
        home = 0;
      }
    }
  }

  return answer.length + '\n' + answer.sort((a, b) => a - b).join('\n');
}
