const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let nums= [];
for(let i=1;i<input.length;i++){
    nums.push(+input[i]);
}

const calcMode=(arr)=>{
    let answer;
    let sH= new Map();
    for(let x of arr){
        if(sH.has(x)) sH.set(x,sH.get(x)+1);
        else sH.set(x,1);
    }
    let max=0;
    sH.forEach((element,key)=>{
       if(max<element){
           max=element;
           answer=[];
           answer.push(key);
       } else if(max===sH.get(key)){
           answer.push(key);
       }
    })
    return answer.length!==1?answer[1]:answer[0];
}

solution(input[0], nums);


function solution(n, arr) {
    const sum = arr.reduce((a,b)=>a+b);
    const sortedArray=arr.sort((a,b)=>a-b);

    console.log(Math.round(sum/n));
    console.log(sortedArray[Math.floor(sortedArray.length/2)]);
    console.log(calcMode(arr));
    console.log(sortedArray[sortedArray.length-1]-sortedArray[0]);
}

