function solution(K, M, A) {
  // Implement your solution here
  // 가장 크게 될 수 있는 수 = 배열 전체 합
  // 가장 작게 단일 값중에서 제일 큰 것보다는 같거나 클수밖에 없음
  let min = Math.max(...A);
  let max = A.reduce((prev, next) => prev + next, 0);
  while (min < max) {
    const mid = Math.floor((min + max) / 2);
    const neededBlocks = getBlocks(A, mid);
    if (neededBlocks > K) {
      // 그 값을 도달하기 위해 필요한 블럭 K보다 크면 더 큰 mid로 더 큰 값을 만들 수 있게 한다.
      min = mid + 1;
    } else {
      max = mid;
    }
  }
  return max;
}
function getBlocks(arr, max) {
  let count = 1;
  let sum = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] + sum > max) {
      sum = arr[i];
      count++;
    } else {
      sum += arr[i];
    }
  }
  return count;
}
