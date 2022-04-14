const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');


console.log(solution(input));

function solution(arr) {
    let answer = [];
    let max = 0;
    let big = 0;
    let Arr = [];
    for (let i = 1; i < arr.length; i++) {
        Arr.push(arr[i].split(" ").map((item) => +item));
    }
    for (let i = 0; i < Arr.length; i++) {
        let [x, y, z] = Arr[i];
        if (x === y && x === z && y === z)    //x==y==z랑은 다른 뜻이다.
            answer[i] = 10000 + x * 1000;
        else if (x === y || x === z)
            answer[i] = 1000 + x * 100;
        else if (y === z)
            answer[i] = 1000 + z * 100;     //z값에 y를 넣어도 된다.
        else {
            if (x > y && x > z)
                max = x;
            else if (y > x && y > z)
                max = y;
            else if (z > x && z > y)
                max = z;                             //3개의 수에서 최댓값을 구하는 코드
            answer[i] = max * 100;
        }
        if (answer[i] > big)
            big = answer[i];
    }
    return big;
}

