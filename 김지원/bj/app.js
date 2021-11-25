const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let Arr=[];
for(let i=1;i<input.length;i++){
    Arr.push(input[i].trim().split(""));
}

solution(Arr);

function solution(arr) {
    let stack=[];
    let flag=0
    for(let i=0;i<arr.length;i++){
        for(let j=0;j<arr[i].length;j++){
            if(arr[i][j]==="(") stack.push(arr[i][j]);
            else if(arr[i][j]===")"&&stack[0]) stack.pop();
            else if(arr[i][j]===")"&&!stack[0]) {
                flag=1
                break;
            }
        }
        if(flag===0&&!stack[0])console.log("YES");
        else console.log("NO");
        flag=0;
        stack=[];
    }

}
