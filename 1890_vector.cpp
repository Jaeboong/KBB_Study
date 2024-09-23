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

    // 오른쪽으로 이동
    if (leftR >= n) {
        //cout << "Shift Right>>" << endl;
        findGoal(leftR - n, leftD, arr[x][y + n], count, arr, x, y + n, "Right " + to_string(n));
    }

    // 아래로 이동
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

    // 2D 동적 배열을 vector로 변경
    vector<vector<int>> arr(n, vector<int>(n));  // n x n 크기의 2차원 벡터 생성

    // 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                finish[0] = j;
                finish[1] = i;
            }
        }
    }

    // 우하단 위치로 이동하는 남은 거리(leftR, leftD) 계산
    leftR = finish[1];
    leftD = finish[0];
    //cout << finish[0] << ", " << finish[1] << endl;
    //cout << "start n: " << arr[0][0] << endl;

    // 좌상단부터 시작하여 경로 찾기
    findGoal(leftR, leftD, arr[0][0], count, arr, 0, 0);

    // 경로의 수 출력
    cout << count << endl;

    return 0;
}
