function solution(participant, completion) {
  participant.sort();
  completion.sort();
  const answerIdx = participant.findIndex(
    (pPerson, idx) => pPerson !== completion[idx]
  );
  const answer = participant[answerIdx];
  return answer;
}
