function rotateArr(A, K) {
  // A는 배열, K는 회전 횟수
  const arr = A;
  if (K === 0) return A;
  if (A.length === 0) return [];
  for (let i = 1; i <= K; i++) {
    const popped = arr.pop();
    arr.unshift(popped);
  }
  return arr;
}
