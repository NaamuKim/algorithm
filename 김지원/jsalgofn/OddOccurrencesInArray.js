function solution(A) {
  const pair = new Map();
  A.forEach((item) => {
    if (pair.has(item)) pair.set(item, pair.get(item) + 1);
    else pair.set(item, 1);
  });
  for (let [key, val] of pair) {
    if (val % 2) return key;
  }
}
