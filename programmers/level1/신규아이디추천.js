function solution(new_id) {
  const step1 = new_id.toLowerCase();
  const step2 = step1.replace(/[^a-z0-9-_\.]/g, '');
  const step3 = step2.replace(/\.+/g, '.');
  const step4_1 = step3.replace(/^\./, '');
  const step4_2 = step4_1.replace(/\.$/, '');
  const step5 = step4_2.length === 0 ? 'a' : step4_2;
  const step6_1 = step5.length >= 16 ? step5.slice(0, 15) : step5;
  const step6_2 = step6_1.replace(/\.$/, '');
  const step7 =
    step6_2.length <= 2
      ? step6_2 + step6_2.charAt(step6_2.length - 1).repeat(3 - step6_2.length)
      : step6_2;
  const answer = step7;
  return answer;
}
