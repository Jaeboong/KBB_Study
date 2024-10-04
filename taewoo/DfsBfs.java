package Programmers_nbc;

import java.util.*;
import java.io.*;

public class DfsBfs {

	// https://www.acmicpc.net/problem/1260

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken()); // 정점의 개수
		int M = Integer.parseInt(st.nextToken()); // 간선의 개수
		int V = Integer.parseInt(st.nextToken()); // 시작 정점
		Graph graph = new Graph(N+1);

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			graph.addEdge(a, b);
		}
		
		graph.dfs(V);
		System.out.println();
		graph.bfs(V);

	}

}

class Graph {
	private int V; // 주어진 정점의 개수;
	private LinkedList<Integer> edge[];

	Graph(int v) {
		this.V = v;
		edge = new LinkedList[v];
		for (int i = 0; i < v; i++) {
			edge[i] = new LinkedList<>(); // i 정점과 연결된 정점을 관리하는 리스트

		}
	}

	// v 와 a 를 연결
	void addEdge(int v, int a) {
		edge[v].add(a);
		edge[a].add(v);
	}

	void printDFS(int v, boolean[] visited) {
		
		visited[v] = true;
		System.out.print(v + " ");
		
		Collections.sort(edge[v]);

		Iterator<Integer> it = edge[v].iterator();
		while (it.hasNext()) {
			int i = it.next();

			if (!visited[i]) { // 방문하지 않은 경우
				printDFS(i, visited);
			}
		}

	}

	void dfs(int v) { // v 부터 dfs 탐색 (모든 정점이 연결된 경우)

		boolean[] visited = new boolean[V];
		printDFS(v, visited);
	}

	void dfs() { // 완전 그래프가 아닌 부분 그래프 인 경우


		boolean[] visited = new boolean[V];

		for (int i = 0; i < V; i++) {
			if (visited[i]) {
				printDFS(i, visited);
			}
		}
	}

	
	
	void bfs(int v) {
		boolean[] visited = new boolean[V];
		
		Queue<Integer> queue = new LinkedList<>();
		visited[v] = true;
		
		queue.add(v);
		
		while(queue.size()!=0) {
			v = queue.poll();
			System.out.print(v + " ");
			
			 Collections.sort(edge[v]);
			
			Iterator<Integer> it = edge[v].iterator();
			while(it.hasNext()) {
				int i = it.next();
				
				if(!visited[i]) {
					visited[i] = true;
					queue.add(i);
				}
			}
		}
		
	}
	
	
}
