const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().split('\n');

input= input[0];

solution(input);

function solution(number) {
    let result = 1;

    for (let i = 1; i < number; i++) {
        result = i;

        const stringValue = i.toString();

        for (let j = 0; j < stringValue.length; j++) {
            result += parseInt(stringValue[j], 10);
        }
        if (result === number) {
            console.log(i);
            return;
        }
    }
    console.log(0);
}
