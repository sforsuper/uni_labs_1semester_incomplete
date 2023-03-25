#pragma once
namespace math {
	struct MatrixSize {
		unsigned rows;
		unsigned cols;
	};

	int** default_matrix(MatrixSize& size);
	int** read_matrix(MatrixSize& size);
	bool has_equal_columns(int** matrix, const MatrixSize& size, unsigned& left_col, unsigned& right_col);
	bool has_prime(int** matrix, const MatrixSize& size, unsigned column_num);
	bool is_prime(int num);
	int abs_summ(int* row, unsigned rows_count);
	void swap(int* left_row, int* right_row, unsigned rows_count);
	void sort_rows_by_abs_summ(int** matrix, const MatrixSize& size);
	void print(int** matrix, const MatrixSize& size);
	void free_memory(int** matrix, const MatrixSize& size);
}

