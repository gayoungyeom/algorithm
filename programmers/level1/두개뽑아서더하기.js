function solution(numbers) {
  let answer = [];
  let curIdx = 0;
  for (let i = curIdx; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      const curSum = numbers[i] + numbers[j];
      if (!answer.includes(curSum)) answer.push(numbers[i] + numbers[j]);
    }
  }
  answer.sort((a, b) => a - b);
  return answer;
}
