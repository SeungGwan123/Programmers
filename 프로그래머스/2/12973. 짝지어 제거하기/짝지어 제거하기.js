function solution(s)
{
    var answer = -1;
    const stack = []
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (stack.length && stack[stack.length - 1] === c) stack.pop();
        else stack.push(c);
    }
    return stack.length === 0 ? 1 : 0;
}