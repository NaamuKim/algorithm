function solution(price, money, count) {
    var answer = -1;
    let sum=0;
    for(let i=1;i<=count;i++){
        sum+=price*i;
    }
    if(sum<=money) return 0
    answer=sum-money;

    return answer;
}