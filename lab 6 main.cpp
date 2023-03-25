#include "func.hpp"
#include <iostream>

using namespace std;
using namespace math;

int main() {
	MatrixSize size;
	int**m = read_matrix(size);
	unsigned left_col;
	unsigned right_col;
	print(m, size);

	if (has_equal_columns(m, size, left_col, right_col)) {
		std::cout << "has equal columns : " << left_col << " " << right_col << std::endl;
		if (has_prime(m, size, left_col)) {
			std::cout << "has primes" << std::endl;
			sort_rows_by_abs_summ(m, size);
		}
	}

	print(m, size);

	free_memory(m, size);
	return 0;
}
