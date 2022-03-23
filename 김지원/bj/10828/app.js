const fs = require('fs');
const path = require('path');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution();

function solution() {
  let stack = [];
  let answer = [];
  for (let i = 1; i < input.length; i++) {
    switch (input[i].split(' ')[0]) {
      case 'push':
        stack.push(Number(input[i].split(' ')[1]));
        break;
      case 'pop':
        if (stack.length) {
          answer.push(stack.pop());
        } else answer.push(-1);
        break;
      case 'top':
        if (stack.length) {
          answer.push(stack[stack.length - 1]);
        } else {
          answer.push(-1);
        }
        break;
      case 'size':
        answer.push(stack.length);
        break;
      case 'empty':
        if (stack.length === 0) answer.push(1);
        else answer.push(0);
        break;
      default:
        break;
    }
  }
  console.log(answer.join('\n'));
}
