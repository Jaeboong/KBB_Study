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

}