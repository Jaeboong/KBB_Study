#include <iostream>
using namespace std;

void Fibonacci(int n1, int n2, int i) {
	int n3 = n1 + n2;
	cout << "F" << i++ << ": " << n3 << endl;
	if(i < 30) Fibonacci(n2, n3, i);
}

int main() {

	int n1 = 0;
	int n2 = 1;
	int i = 3;

	cout << "F1: 0" << endl << "F2: 1" << endl;

	Fibonacci(n1, n2, i);

	return 0;
}