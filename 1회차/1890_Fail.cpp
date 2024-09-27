#include <iostream>
using namespace std;

void findGoal(int *leftR, int *leftD, int n, int* count, int **arr, int x, int y) {
    if (*leftR == 0 && *leftD == 0) {
        (*count)++;
        cout << "find goal: " << x << " " << y << endl;
    }
    else {
        if (*leftR >= n) {
            cout << "location: " << y << ", " << x << endl;
            cout << "n: " << n << "   leftR: " 
                << *leftR << "    leftD: " << *leftD << endl;
            *leftR -= n;
            int tmpn = n;
            cout << "y+n: " << y << "+" << n << endl;
            n = arr[x][y + n];
            cout << "shitR 실행" << endl;
            findGoal(leftR, leftD, n, count, arr, x, y + tmpn);
        }
        if (*leftD >= n) {
            cout << "location: " << y << ", " << x << endl;
            cout << "n: " << n << "   leftR: "
                << *leftR << "    leftD: " << *leftD << endl;
            *leftD -= n;
            int tmpn = n;
            n = arr[x + n][y];
            cout << "shitD 실행" << endl;
            findGoal(leftR, leftD, n, count, arr, x + tmpn , y);
        }
    }
}

int main() {
    int n, count = 0;
    cin >> n; 
    int finish[2] = { 0, 0 };
    int leftR, leftD;

    int** arr = new int* [n];  
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];  
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                finish[0] = j;
                finish[1] = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    leftR = finish[1];
    leftD = finish[0];
    cout << finish[0] << ", " << finish[1] << endl;
    cout << "start n: " << arr[0][0] << endl;
    findGoal(&leftR, &leftD, arr[0][0], &count, arr, 0, 0);

    cout << "count: " << count << endl;

    for (int i = 0; i < n; i++) {
        delete[] arr[i];  
    }
    delete[] arr;  

    return 0;
}
