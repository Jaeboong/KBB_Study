#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <vector>   // std::vector
using namespace std;
using namespace std;


void bubbleSort(int arr[], int n) {
	int tmp = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	srand((unsigned)time(0));
	int arr[10];
	vector<int> uniqueNumbers;

	while (uniqueNumbers.size() < 10) {
		int num = rand() % 99 + 1;
		// 중복 방지를 위해 숫자가 vector에 없을 경우 추가
		if (find(uniqueNumbers.begin(), uniqueNumbers.end(), num) == uniqueNumbers.end()) {
			uniqueNumbers.push_back(num);
		}
	}

	int index = 0;
	for (int num : uniqueNumbers) {
		arr[index++] = num;
	}

	cout << "array size: " << size(arr) << endl;

	cout << "Original array: ";
	printArray(arr, size(arr));

	bubbleSort(arr, size(arr));

	cout << "Sorted array: ";
	printArray(arr, size(arr));

	 
	return 0;
}