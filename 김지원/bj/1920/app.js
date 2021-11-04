const fs=require("fs");
const filePath=process.platform==='linux' ? "/dev/stdin" : './input.txt';
let input= fs.readFileSync(filePath).toString().trim().split('\n');

let arr1=input[1].split(" ").map((item=>+item));
let arr2=input[3].split(" ").map((item=>+item));
solution(arr1,arr2);

function solution(arr1,arr2) {
        arr1.sort((a,b)=>a-b);
        const binary=(target)=>{
            let lt=0,rt=arr1.length-1;
            while(lt<=rt){
            let mid=parseInt((lt+rt)/2);
            if(arr1[mid]===target){
                return 1;
            }
            else if(arr1[mid]>target) rt=mid-1;
            else {
                lt=mid+1;
            }
        }
        return 0;
        }
    arr2.map(v=>console.log(binary(v)));

}
