const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');


console.log(solution(input));

function solution(arr) {
    let answer = "";
    let n=+input[0]
    let Arr=input[2].split(" ").map((item)=>+item);
    const candidates=new Map();
    for (let i = 0; i < Arr.length; i++) {
        let num = Arr[i];

        if (candidates.has(num)) {
            candidates.get(num)[0]++;
        } else {
            if (candidates.size === n) {
                let min = null;

                for ([key, value] of candidates.entries()) {
                    if (!min) {
                        min = [key, value];
                        continue;
                    }

                    const [minCnt, minTime] = min[1];
                    const [nowCnt, nowTime] = value;

                    if (nowCnt < minCnt || (nowCnt === minCnt && nowTime < minTime)) {
                        min = [key, value];
                    }
                }

                candidates.delete(min[0]);
            }

            candidates.set(num, [1, i]);
        }
    }
    [...candidates.keys()].sort((a, b) => a - b).forEach((candidate) =>  (answer += candidate + " "));

    return answer;
}
