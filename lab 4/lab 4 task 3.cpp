// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	int matrix[101][101];
	int n, m; 
	std::cin >> n >> m;
	int min = INT_MAX;
	int index = -1;
	for (int i = 0; i < n; i++) {
		int result = 0;
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j]; 
			result += matrix[i][j];
		}
		if (std::abs(result) < min) {
			min = std::abs(result);
			index = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (index == i) {
			for (int j = 0; j < m; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	
}
