#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 입력 배열
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // DP 테이블 (경로의 수를 저장할 테이블)
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;  // 시작점

    // 동적 계획법을 이용해 경로 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 현재 위치의 dp 값 출력
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;

            // 만약 현재 위치가 도착점이면 건너뛰기
            if (i == n - 1 && j == n - 1) {
                continue;
            }

            int step = arr[i][j];  // 현재 위치에서 이동할 수 있는 칸 수
            cout << "arr[" << i << "][" << j << "] = " << step << endl;

            if (step == 0) continue;  // 0이면 더 이상 진행 불가

            // 오른쪽으로 이동할 수 있는지 확인
            if (j + step < n) {
                dp[i][j + step] += dp[i][j];  // 오른쪽으로 이동
                cout << "Moving right to dp[" << i << "][" << j + step << "] now becomes " << dp[i][j + step] << endl;
            }

            // 아래로 이동할 수 있는지 확인
            if (i + step < n) {
                dp[i + step][j] += dp[i][j];  // 아래로 이동
                cout << "Moving down to dp[" << i + step << "][" << j << "] now becomes " << dp[i + step][j] << endl;
            }

            // DP 테이블 출력
            cout << "Current dp table after processing position (" << i << "," << j << "):\n";
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    cout << dp[x][y] << " ";
                }
                cout << endl;
            }
            cout << "---------------------\n";
        }
    }

    // 최종 dp 테이블 출력
    cout << "Final dp table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // 우하단에 도달할 수 있는 경로의 수 출력
    cout << "Number of paths to reach dp[" << n - 1 << "][" << n - 1 << "]: " << dp[n - 1][n - 1] << endl;

    return 0;
}
