package Programmers_nbc;

import java.util.*;
import java.io.*;
//https://www.acmicpc.net/problem/1890


public class Jump {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());

		int[][] arr = new int[N][N]; // 입력 저장할 배열
		long[][] way = new long[N][N]; // 각 자리수마다 도착 가능한 방법의 수 (넉넉하게 잡아야함)

		for (int i = 0; i < arr.length; i++) {

			st = new StringTokenizer(br.readLine());

			for (int j = 0; j < arr[i].length; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		// 여기 까지가 입력부

		way[0][0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (i == N - 1 && j == N - 1)
					break; // 마지막 칸 종료

				if (arr[i][j] > 0) { // way[i][j] >0 조건으로 변경해도 정답 (차피 못가는 경우라 그런듯)
					// 논리적으로는 arr 이 맞는듯 아래 식이 way 값을 통해 업데이트 되기 때문
					if (i + arr[i][j] < N) {
						way[i + arr[i][j]][j] += way[i][j];
					}
					if (j + arr[i][j] < N) {
						way[i][j + arr[i][j]] += way[i][j];
					}

				}

			}
		}


		System.out.println(way[N - 1][N - 1]);
	}
}
