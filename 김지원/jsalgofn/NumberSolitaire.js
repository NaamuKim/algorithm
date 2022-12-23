function solution(A) {
  // Implement your solution here
  const DP = new Array(A.length).fill(-Infinity);
  // A[0] 값부터 시작
  DP[0] = A[0];

  for (let i = 1; i < A.length; i++) {
    for (let j = Math.max(0, i - 6); j < i; j++) {
      // 주사위로 가능한 경우에서 제일 큰 결과 값
      // ex i가 7이면 1~6까지 나온 값중에서 제일 큰값이랑 7을 더한 게 7까지 온 경우중에 제일 큰 것
      DP[i] = Math.max(DP[i], DP[j] + A[i]);
    }
  }
  return DP[A.length - 1];
}
