const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

const arr = [];
for (let i = 1; i < input.length; i++) {
  arr.push(input[i].split('').map((item) => +item));
}
console.log(solution(arr));

function solution(board) {
  let answer = Number.MAX_SAFE_INTEGER;
  let newAnswer = 0;
  let dx = [-1, 0, 1, 0];
  let dy = [0, 1, 0, -1];
  const [xlength, ylength] = input[0].split(' ').map((item) => +item - 1);
  function DFS(x, y) {
    if (x === xlength && y === ylength) {
      answer = Math.min(answer, newAnswer);
    } else {
      for (let i = 0; i <= 3; i++) {
        let newX = x + dx[i];
        let newY = y + dy[i]; 
        if (newX >= 0 && newX <= xlength && newY >= 0 && newY <= ylength && board[newX][newY] === 1) {
          board[newX][newY] = 0;
          newAnswer++;
          DFS(newX, newY);
          board[newX][newY] = 1;
        }
      }
    }
  }
  board[0][0] = 0;
  DFS(0, 0);
  return answer;
}
