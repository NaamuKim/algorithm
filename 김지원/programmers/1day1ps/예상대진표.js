function solution(n,a,b)
{
    let answer = 1;
    // 일단 무조건 b가 더 큰 상황을 만들자
    let temp;
    if(a>b) {
        temp=b;
        b=a;
        a=temp;
    }
    while(a+1!==b||a%2===0){
        answer++;
        a=Math.ceil(a/2);
        b=Math.ceil(b/2);
    }
    return answer;
}