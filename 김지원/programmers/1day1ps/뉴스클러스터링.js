const MUL = 65536;

function solution(str1, str2) {
  // 문자열을 가공한 배열을 만든다.
  const arr1 = splitStr(str1);
  const arr2 = splitStr(str2);
  const [unionLength, interLength] = getLength(arr1, arr2);
  // 비교한다.
  if (unionLength === 0) return MUL;
  const answer = (interLength / unionLength) * MUL;
  return Math.floor(answer);
}

function splitStr(str) {
  const ret = [];
  for (let i = 0; i < str.length - 1; i++) {
    const word = str[i] + str[i + 1];
    if (isEnglish(String(word))) {
      ret.push(word.toLowerCase());
    }
  }
  return ret;
}

function isEnglish(word) {
  const regEx = /^[a-z|A-Z]+$/;
  return regEx.test(word);
}

function getLength(arr1, arr2) {
  // 합집합의 의미는 둘다 합치고 길이가 남는 거 삭제
  const sumArr = new Set([...arr1, ...arr2]);
  let unionLength = 0,
    interLength = 0;
  sumArr.forEach((item) => {
    unionLength += Math.max(arr1.filter((it1) => item === it1).length, arr2.filter((it2) => item === it2).length);
    interLength += Math.min(arr1.filter((it1) => item === it1).length, arr2.filter((it2) => item === it2).length);
  });
  return [unionLength, interLength];
}
solution('FRANCE', 'french');
solution('handshake', 'shake hands');
solution('aa1+aa2', 'AAAA12');
