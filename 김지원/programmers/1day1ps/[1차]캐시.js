function solution(cacheSize, cities) {
  const CACHE_HIT = 1;
  const CACHE_MISS = 5;
  let answer = 0;
  let cache = [];
  if (cacheSize === 0) return CACHE_MISS * cities.length;
  for (let i = 0; i < cities.length; i++) {
    if (cache.includes(cities[i])) {
      answer += CACHE_HIT;
      cache = cache.filter((city) => city !== cities[i]);
      cache.push(cities[i]);
    } else {
      answer += CACHE_MISS;
      if (cache.length === cacheSize) {
        cache.shift();
      }
      cache.push(cities[i]);
    }
  }
  return answer;
}
//no for solution
function solution(cacheSize, cities) {
  const CACHE_HIT = 1;
  const CACHE_MISS = 5;
  let answer = 0;
  let cache = [];
  if (cacheSize === 0) return CACHE_MISS * cities.length;
  cities.forEach((item) => {
    item = item.toLowerCase();
    if (cache.includes(item)) {
      answer += CACHE_HIT;
      cache = cache.filter((city) => city !== item);
      cache.push(item);
    } else {
      answer += CACHE_MISS;
      if (cache.length === cacheSize) {
        cache.shift();
      }
      cache.push(item);
    }
  });
  return answer;
}
