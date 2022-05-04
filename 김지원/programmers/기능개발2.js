function solution(progresses, speeds) {
  let answer = [0];
  let days = progresses.map((progress, index) => Math.ceil((100 - progress) / speeds[index]));
  //[7,3,9]
  let maxDay = days[0];
  //7
  for (let i = 0, j = 0; i < days.length; i++) {
    if (days[i] <= maxDay) {
      //처음에는 첫번째 애가 나갈 수
      answer[j] += 1;
    } else {
      maxDay = days[i];
      answer[++j] = 1;
    }
  }

  return answer;
}
