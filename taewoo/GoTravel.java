package Programmers_nbc;

//https://www.acmicpc.net/problem/1976
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class GoTravel {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());// 도시의 수
		int M = Integer.parseInt(br.readLine()); // 계획한 도시의 수

		StringTokenizer st;

		int[][] bridge = new int[N][N]; // 연결 여부를 나타내는 2차원 배열
		int[] parent = new int[N]; // 각 노드의 부모를 나타냄 초기에는 자기 자신으로 초기화
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				bridge[i][j] = Integer.parseInt(st.nextToken());
				if (bridge[i][j] == 1) {
					union(parent, i, j);
				}

			}
		} // 연결 여부 입력

		int[] trip_plan = new int[M];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			trip_plan[i] = Integer.parseInt(st.nextToken());

		} // 여행 계획 입력
		
		// -------------------------------- 입력 종료 --------------------------------------
		
		

		boolean flag = true; // 처음엔 다 방문가능 하다고 가정
		for (int i = 0; i < M - 1; i++) {

			// 0번 노드부터 시작하도록 해서 -1 을 처리함
			if (union_find(parent, trip_plan[i] - 1) != union_find(parent, trip_plan[i + 1] - 1)) {
				System.out.println("NO");
				flag = false;
				break;
			}
		}
		if (flag) {
			System.out.println("YES");
		}
		//System.out.println(Arrays.toString(parent));

	}

	public static int union_find(int[] parent, int node) {

		if (parent[node] == node) {
			return node; // root 를 나타냄
		} else {
			return parent[node] = union_find(parent, parent[node]);
			// 더 큰 조상이 존재함
		}

	}

	public static void union(int[] parent, int node1, int node2) { // 연결이 가능한 경우 실행되는 메서드

		int root1 = union_find(parent, node1);
		int root2 = union_find(parent, node2);

		if (root1 != root2) {
			parent[root2] = root1;
		}
	}

}
