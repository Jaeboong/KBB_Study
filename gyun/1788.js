const fs = require('fs');
const n = parseInt(fs.readFileSync('./input.txt').toString());
const MAX = 1000000000;

//피보나치
function fibonacci(n) {
    if (n === 0) return 0;

    else if (n === 1 || n === -1) return 1;

    else{
    let prev = 0, curr = 1;

    for (let i = 2; i <= Math.abs(n); i++) {
        let next = (prev + curr) % MAX;
        prev = curr;
        curr = next;
    }

    return curr;
}
}

// 부호 출력
function getSign(n) {
    if (n === 0) return 0; 
    if (n > 0) return 1;   // 양수일 때
    // 음수일 때 홀수면 양수 짝수면 음수
    return (Math.abs(n) % 2 === 0) ? -1 : 1;
}

const sign = getSign(n);
const absFibonacci = fibonacci(n);

console.log(sign);
console.log(absFibonacci);