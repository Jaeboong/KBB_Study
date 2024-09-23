#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a, b;

    cin >> n;
    int* result = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int tmp = 1;
        for (int j = 1; j <= b; j++) {
            tmp *= a;
            if (tmp % 10 == 0) {
                tmp = 10;
            }
            else {
                tmp = tmp % 10;
            }
        }
        result[i] = tmp;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }
    return 0;
}