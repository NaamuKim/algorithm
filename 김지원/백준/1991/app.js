const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');
// const N = Number(input[0]);
const tree = {};
let result = '';
input = input.slice(1);

console.log(solution());

function solution() {
  input.forEach((item) => {
    const [node, left, right] = item.split(' ');
    tree[node] = [left, right];
  });
  preorder('A');
  result += '\n';
  inorder('A');
  result += '\n';
  postorder('A');
  return result;
}
function preorder(node) {
  if (node === '.') return;
  const [lt, rt] = tree[node];
  result += node;
  preorder(lt);
  preorder(rt);
}
function inorder(node) {
  if (node === '.') return;
  const [lt, rt] = tree[node];
  inorder(lt);
  result += node;
  inorder(rt);
}
function postorder(node) {
  if (node === '.') return;
  const [lt, rt] = tree[node];
  postorder(lt);
  postorder(rt);
  result += node;
}
