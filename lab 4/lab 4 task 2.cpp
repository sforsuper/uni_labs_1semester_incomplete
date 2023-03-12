// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int firstDigit(int n) {
	int result = 0;
	while (n > 0) {
		result = n % 10;
		n /= 10;
	}
	return result;
}
int sum(int n) {
	int sresult = 0;
	while (n > 0) {
		sresult += n % 10;
		n /= 10;
	
	}
	return sresult;
}

void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (firstDigit(arr[j]) > firstDigit(arr[j + 1])) {
				std::swap(arr[j], arr[j + 1]);
			}
			if (firstDigit(arr[j]) == firstDigit(arr[j + 1])) {
				if (sum(arr[j]) > sum(arr[j + 1])) {
					std::swap(arr[j], arr[j + 1]);
				}
				if (sum(arr[j]) == sum(arr[j + 1])) {
					if (arr[j] > arr[j + 1]) {
						std::swap(arr[j], arr[j + 1]);
					}
				}
			}
		}
	}
}
int main()
{
	int mas[10001];
	short int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> mas[i];
	}
	bubbleSort(mas, n);
	for (int i = 0; i < n; i++) {
		std::cout << mas[i] << " ";
	}
}
