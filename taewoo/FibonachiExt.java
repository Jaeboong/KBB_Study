package Programmers_nbc;

import java.util.Scanner;

//https://www.acmicpc.net/problem/1788
public class FibonachiExt {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		int result1, result2;

		int n = scanner.nextInt();
		final int DIV = 1_000_000_000;

		// result1 처리
		if (n == 0) { // 0번째
			result1 = 0;
		} else if (n > 0 || n % 2 != 0) { // 짝수번째와 양의 정수
			result1 = 1;
		} else { // 음수인 경우
			result1 = -1;
		}

		n = Math.abs(n);

		int[] Fibo = new int[Math.max(n + 1, 2)]; // 이렇게 안하고 한번에 할당 시 메모리 초과

		Fibo[0] = 0;
		Fibo[1] = 1;

		for (int i = 2; i < n + 1; i++) {
			Fibo[i] = (Fibo[i - 1] + Fibo[i - 2]) % DIV;
		}

		// result2 처리
		result2 = Fibo[n];

		System.out.println(result1);
		System.out.println(result2);
	}

}
