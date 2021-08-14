import { readFileSync } from "fs";
let input = readFileSync("/dev/stdin").toString().split(" ");
let str = Number(input);
function solution(s) {
	let answer;
	let stack = [];
	for (let x of s) {
		if (x === ")") {
			while (stack.pop() !== "(");
		} else stack.push(x);
	}
	answer = stack.join("");
	return answer;
}

console.log(solution(str));
