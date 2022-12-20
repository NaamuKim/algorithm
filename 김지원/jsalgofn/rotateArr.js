function rotateArr(A, K) {
  // Implement your solution here
  const arr = A;
  if (K === 0) return A;
  if (A.length === 0) return [];
  for (let i = 1; i <= K; i++) {
    const popped = arr.pop();
    arr.unshift(popped);
  }
  return arr;
}
