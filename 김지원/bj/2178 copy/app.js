const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = [];
for (let i = 1; i < input.length; i++) {
  arr.push(input[i].split('').map((item) => +item));
}
const [xlength, ylength] = input[0].split(' ').map((item) => +item);
const check = Array.from({ length: xlength }, () => Array(ylength).fill(0));
console.log(solution(arr));

function solution(board) {
  const dx = [-1, 0, 1, 0];
  const dy = [0, 1, 0, -1];

  function BFS(x, y) {
    const queue = [];
    queue.push([x, y]);

    check[x][y] = 1;
    while (queue.length) {
      const [x, y] = queue.shift();
      for (let i = 0; i < 4; i++) {
        const [nx, ny] = [x + dx[i], y + dy[i]];
        if (nx < 0 || ny < 0 || nx >= xlength || ny >= ylength) continue;
        if (board[x][y] === 1 && !check[nx][ny]) {
          check[nx][ny] = check[x][y] + 1;
          queue.push([nx, ny]);
        }
      }
    }
  }
  BFS(0, 0);
  return check[xlength - 1][ylength - 1];
}
