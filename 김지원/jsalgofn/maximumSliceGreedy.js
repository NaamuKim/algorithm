function solution(A, B) {
  // Implement your solution here
  if (!A.length || !B.length) return 0;
  let answer = 1;
  let end = B[0];
  for (let i = 1; i < A.length; i++) {
    if (end < A[i]) {
      end = B[i];
      answer++;
    }
  }
  return answer;
}
