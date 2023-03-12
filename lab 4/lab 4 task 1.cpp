
#include <iostream>
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);

}

int main()
{
	const int N = 10001;
	int mas[N];

	short int n;
	std::cin >> n;
	int number;
	int first;
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		std::cin >> number;
		mas[i] = number;
		first = number;
		while (first >= 10)
			first /= 10;
		if (first == 1)
			check = true;
	}
	if (check == true)
	{
		bubbleSort(mas, n);

	}
	for (int i = 0; i < n; i++)
	{
		std::cout << mas[i] << " ";
	}
}


