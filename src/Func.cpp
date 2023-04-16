#include "Func.hpp"
#include <iostream>

namespace math {

    int** default_matrix(MatrixSize& size) {
        size.rows = 3;
        size.cols = 3;
        int** matrix = new int*[size.rows];
        for (unsigned i = 0; i < size.cols; i++) {
            matrix[i] = new int[size.cols];
        }
        matrix[0][0] = 3;
        matrix[0][1] = 1;
        matrix[0][2] = 3;

        matrix[1][0] = 1;
        matrix[1][1] = 2;
        matrix[1][2] = 1;

        matrix[2][0] = 11;
        matrix[2][1] = 3;
        matrix[2][2] = 11;

        return matrix;
    }

    int** read_matrix(MatrixSize& size) {
        std::cout << "write size: ";
        std::cin >> size.rows;
        std::cin >> size.cols;

        int** matrix = new int*[size.rows];
        for (unsigned i = 0; i < size.cols; i++) {
            matrix[i] = new int[size.cols];
        }
        std::cout << "write matrix\n";
        for (unsigned i = 0; i < size.rows; i++)
            for (unsigned j = 0; j < size.cols; j++)
                std::cin >> matrix[i][j];
        return matrix;
    }

    bool has_equal_columns(int** matrix, const MatrixSize& size, unsigned& left_col, unsigned& right_col) {

        for (unsigned j = 0; j < size.cols - 1; j++) {
            for (unsigned i = j + 1; i < size.cols; i++) {
                bool check = true;
                for (unsigned row = 0; row < size.rows; row++) {
                    if (matrix[row][j] != matrix[row][i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    left_col = j;
                    right_col = i;
                    return true;
                }
            }
        }
        return false;
    }

    bool has_prime(int** matrix, const MatrixSize& size, unsigned column_num) {
        for (unsigned i = 0; i < size.rows; i++) {
            if (is_prime(matrix[i][column_num])) {
                return true;
            }
        }
        return false;
    }

    bool is_prime(int num) {
        if (num == 1) return false;
        int limit = num / 2;
        for (int i = 2; i < limit; i++) {
            if (num%i == 0) return false;
        }
        return true;
    }

    int abs_summ(int* row, unsigned rows_count) {
        int summ = 0;
        for (unsigned i = 0; i < rows_count; i++) {
            summ += row[i];
        }
        return summ;
    }

    void swap(int* left_row, int* right_row, unsigned rows_count) {
        int temp = 0;
        for (unsigned i = 0; i < rows_count; i++) {
            temp = left_row[i];
            left_row[i] = right_row[i];
            right_row[i] = temp;
        }
    }


    void sort_rows_by_abs_summ(int** matrix, const MatrixSize& size) {
        for (unsigned i = 0; i < size.rows - 1; i++) {
            for (unsigned j = 0; j < size.rows - i - 1; j++) {
                if (abs_summ(matrix[j], size.rows) > abs_summ(matrix[j+1], size.rows)) {
                    swap(matrix[j], matrix[j+1], size.rows);
                }
            }
        }
        print(matrix, size);
    }

    void print(int** matrix, const MatrixSize& size) {
        for (unsigned i = 0; i < size.rows; i++) {
            for (unsigned j = 0; j < size.cols; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void free_memory(int** matrix, const MatrixSize& size) {
        for (size_t i = 0; i < size.rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

}