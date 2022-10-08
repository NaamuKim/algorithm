function solution(s) {
  var answer = [];
  //배열에 담아서
  const arr = s
    .slice(2, -2)
    .split('},{')
    .map((item) => item.split(','))
    .map((item) => item.map((item) => +item))
    .sort((a, b) => a.length - b.length);
  //배열 길이가 작은 것부터 담고 긴 배열에서 아직 안나온 게 있으면 뒤에다가 넣는 방식
  for (const item of arr) {
    answer.push(...item.filter((newItem) => !answer.includes(newItem)));
  }
  return answer;
}
console.log(solution('{{2},{2,1},{2,1,3},{2,1,3,4}}'));
console.log(solution('{{1,2,3},{2,1},{1,2,4,3},{2}}'));
