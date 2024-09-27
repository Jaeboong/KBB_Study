#include <iostream>
#include <vector>
#include <string>
using namespace std;

void findGoal(int leftR, int leftD, int n, int& count, const vector<vector<int>>& arr, int x, int y, string lastMove = "Start") {
    //cout << "Current position: (" << y << ", " << x << ")" << endl;
    //cout << "Remaining moves: Right = " << leftR << ", Down = " << leftD << endl;
    //cout << "Current n: " << n << endl << endl;

    if (leftR == 0 && leftD == 0) {
        count++;
        //cout << "Goal found at (" << y << ", " << x << ")!" << endl;
        //cout << "Total paths found: " << count << endl << endl;
        return;
    }

    // ���������� �̵�
    if (leftR >= n) {
        //cout << "Shift Right>>" << endl;
        findGoal(leftR - n, leftD, arr[x][y + n], count, arr, x, y + n, "Right " + to_string(n));
    }

    // �Ʒ��� �̵�
    if (leftD >= n) {
        //cout << "Shift Down>>" << endl;
        findGoal(leftR, leftD - n, arr[x + n][y], count, arr, x + n, y, "Down " + to_string(n));
    }
}

int main() {
    int n, count = 0;
    cin >> n;
    int finish[2] = { 0, 0 };
    int leftR, leftD;

    // 2D ���� �迭�� vector�� ����
    vector<vector<int>> arr(n, vector<int>(n));  // n x n ũ���� 2���� ���� ����

    // �Է¹ޱ�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                finish[0] = j;
                finish[1] = i;
            }
        }
    }

    // ���ϴ� ��ġ�� �̵��ϴ� ���� �Ÿ�(leftR, leftD) ���
    leftR = finish[1];
    leftD = finish[0];
    //cout << finish[0] << ", " << finish[1] << endl;
    //cout << "start n: " << arr[0][0] << endl;

    // �»�ܺ��� �����Ͽ� ��� ã��
    findGoal(leftR, leftD, arr[0][0], count, arr, 0, 0);

    // ����� �� ���
    cout << count << endl;

    return 0;
}
