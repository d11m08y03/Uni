#include <cstddef>
#include <vector>
#include <iostream>

struct Matrix {
  size_t rows, cols;
  std::vector<std::vector<int>> arr;

  Matrix(size_t rows, size_t cols, std::vector<std::vector<int>> arr) : rows(rows), cols(cols), arr(arr) {}

  void display() {
    for (size_t i = 0; i < this->rows; i++) {
      for (size_t j = 0; j < this->cols; j++) {
        std::clog << this->arr[i][j] << '\t';
      }
      std::clog << '\n';
    }
  }

  Matrix operator * (Matrix const& rhs) {
    Matrix result(
      this->rows, 
      rhs.cols, 
      std::vector<std::vector<int>> (this->rows, std::vector(rhs.cols, 0))
    );

    if (this->cols != rhs.rows) {
      std::cerr << "Cannot multiply matrices.\n";
      return result;
    }

    for (size_t i = 0; i < this->rows; i++) {
      for (size_t j = 0; j < rhs.cols; j++) {
        for (size_t k = 0; k < rhs.cols; k++) {
          result.arr[i][j] += this->arr[i][k] * rhs.arr[k][j];
        }
      }
    }

    return result;
  }
};


int main(void) {
  Matrix A(3, 2, {{1, 2}, {1, 2}, {1, 2}});
  Matrix B(2, 2, {{1, 2}, {1, 2}});
  Matrix C = A * B;
  C.display();
}
