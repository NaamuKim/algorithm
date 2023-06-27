const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const [N, M] = input.shift().split(' ').map(Number);

const arr = Array.from({ length: N + 1 }, () => []);
input.forEach((item) => {
  const [a, b] = item.split(' ').map(Number);
  arr[a].push(b);
  arr[b].push(a);
});

function solution() {
  console.log(arr);
}
function floyd() {
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {
      for (let k = 1; j <= N; k++) {
        if (arr[i][j] > arr[i][k] + arr[k][j]) {
          arr[i][j] = arr[i][k] + arr[k][j];
        }
      }
    }
  }
}

console.log(solution());
