const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let Arr=[];
for(let i=1;i<input.length;i++){
    Arr.push(input[i].split(" ").map((item)=>Number(item)));
}


solution(Arr);

function solution(arr) {
    for(let i=0;i<arr.length;i++){
        let distanceWithTurret=Math.sqrt((arr[i][3]-arr[i][0])*(arr[i][3]-arr[i][0])+(arr[i][4]-arr[i][1])*(arr[i][4]-arr[i][1]))
        let expectedDistanceSum=arr[i][2]+arr[i][5];
        let expectedDistanceSub= Math.abs(Arr[i][2]-arr[i][5]);

        if(distanceWithTurret<expectedDistanceSum&&distanceWithTurret>expectedDistanceSub) console.log(2);
        else if(distanceWithTurret===expectedDistanceSum||(distanceWithTurret===expectedDistanceSub&&distanceWithTurret!==0)) console.log(1);
        else if(distanceWithTurret<expectedDistanceSub||distanceWithTurret>expectedDistanceSum) console.log(0);
        else if(distanceWithTurret===0){
            if(expectedDistanceSub===0) console.log(-1)
            else console.log(0);
        }

    }
}
