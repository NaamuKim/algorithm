function solution(bridge_length, weight, truck_weights) {
  var answer = 0;
  let bridge = [];
  let bridge_weight = 0;
  //시간은 1. 다리에 넣기만 하는 시간, 2. 다리에 넣지는 못하지만 다리를 건너면서 시간이 흐르는 시간 3. 마지막 친구가 다리를 건너는 시간 answer= 1+ 2+ 3이다.
  while (truck_weights.length > 0) {
    //대기 트럭이 없어질 때까지
    answer++; //while문 한번당 시간 1초씩 지남
    if (bridge.length == bridge_length) {
      //다리 꽉차있으면
      bridge_weight -= bridge.shift(); //다리에서 하나 뺀다
    }
    if (bridge_weight + truck_weights[0] > weight) {
      //다리에 새로운 트럭을 넣을 수 없으면
      bridge.push(0); //다리에 0을 push 우리는 꽉차있을 때만 뺄 수 있음
      continue; //밑에부분 안되게
    }
    //continue안됐으면 다리에 여유가 있음
    let truck_weight = truck_weights.shift();
    bridge.push(truck_weight); //다리에 넣는다
    bridge_weight += truck_weight; //다리무게에도 트럭무게를 포함시킨다
  }
  answer += bridge_length;
  return answer;
}
