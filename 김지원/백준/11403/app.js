const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
const n = +input.shift();
const arr = input.map((item) => item.split(' ').map(Number));

const solution = () => {
  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        // k를 거쳐서 i부터 j까지 갈 수 있다
        // ex 1을 거쳐서 0부터 2까지 갈 수 있다면
        // arr[0][1]이 1이어야 0에서 1을 가고 arr[1][2]이 1이어야 갈 수 있다.
        // ex 2를 거쳐서 0부터 3까지 갈 수 있다면
        // arr[0][2]가 갈 수 있고 arr[2][3]이 갈수 있으면 됨
        if (arr[i][k] && arr[k][j]) {
          arr[i][j] = 1;
        }
      }
    }
  }
  arr.forEach((item) => {
    console.log(item.join(' '));
  });
};

solution();
