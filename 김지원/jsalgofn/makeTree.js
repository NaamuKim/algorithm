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
