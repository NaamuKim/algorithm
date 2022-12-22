function solution(X, A) {
  const arr = [];
  let result = -1;
  for (let i = 0; i < A.length; i++) {
    if (typeof arr[A[i]] === 'undefined') arr[A[i]] = i;
  }
  if (arr.length <= X) return -1;
  for (let i = 1; i <= X; i++) {
    if (typeof arr[i] === 'undefined') return -1;
    result = Math.max(result, arr[i]);
  }
  return result;
}
