#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // �Է� �迭
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // DP ���̺� (����� ���� ������ ���̺�)
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;  // ������

    // ���� ��ȹ���� �̿��� ��� ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ���� ��ġ�� dp �� ���
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;

            // ���� ���� ��ġ�� �������̸� �ǳʶٱ�
            if (i == n - 1 && j == n - 1) {
                continue;
            }

            int step = arr[i][j];  // ���� ��ġ���� �̵��� �� �ִ� ĭ ��
            cout << "arr[" << i << "][" << j << "] = " << step << endl;

            if (step == 0) continue;  // 0�̸� �� �̻� ���� �Ұ�

            // ���������� �̵��� �� �ִ��� Ȯ��
            if (j + step < n) {
                dp[i][j + step] += dp[i][j];  // ���������� �̵�
                cout << "Moving right to dp[" << i << "][" << j + step << "] now becomes " << dp[i][j + step] << endl;
            }

            // �Ʒ��� �̵��� �� �ִ��� Ȯ��
            if (i + step < n) {
                dp[i + step][j] += dp[i][j];  // �Ʒ��� �̵�
                cout << "Moving down to dp[" << i + step << "][" << j << "] now becomes " << dp[i + step][j] << endl;
            }

            // DP ���̺� ���
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

    // ���� dp ���̺� ���
    cout << "Final dp table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // ���ϴܿ� ������ �� �ִ� ����� �� ���
    cout << "Number of paths to reach dp[" << n - 1 << "][" << n - 1 << "]: " << dp[n - 1][n - 1] << endl;

    return 0;
}
