// 사용 전에 정렬을 전제한다.
const binarySearch = (arr, target) => {
  let le = 0,
    ri = arr.length;
  while (le < ri) {
    const mid = Math.floor((le + ri) / 2);
    if (target === arr[mid]) {
      return mid;
    } else if (target < arr[mid]) {
      ri = mid;
    } else {
      le = mid + 1;
    }
  }
  // target이 없을 땐 -1
  return -1;
};
