#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

// 계수 정렬을 이용한 정렬 함수
void countingSort(vector<int>& arr, int n) {
    vector<int> count(n + 1, 0);
    vector<int> output(arr.size());

    for (int i : arr) {
        count[i]++;
    }

    int index = 0;
    for (int i = 1; i <= n; i++) {
        while (count[i] > 0) {
            output[index++] = i;
            count[i]--;
        }
    }

    arr = output;
}

// DFS 함수
void dfs(int v) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < graph[v].size(); i++) {
        int adjacent = graph[v][i];
        if (!visited[adjacent]) {
            dfs(adjacent);
        }
    }
}

// BFS 함수
void bfs(int start) {
    queue<int> q;
    visited.assign(visited.size(), false);
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i : graph[v]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 각 정점의 인접 리스트 정렬
    for (int i = 1; i <= n; i++) {
        countingSort(graph[i], n);
    }

    dfs(start);
    cout << endl;
    bfs(start);

    return 0;
}