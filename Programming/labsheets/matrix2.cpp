#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <ranges>
#include <stdexcept>
#include <vector>

struct Matrix {
  size_t rows, cols;
  std::vector<int> arr;

  Matrix(size_t rows, size_t cols, std::vector<int> arr)
      : rows(rows), cols(cols), arr(arr) {}

  Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    this->arr = std::vector(rows * cols, 0);
  }

  Matrix operator*(Matrix const &rhs) const {
    if (this->cols != rhs.cols) {
      throw std::invalid_argument("Cannot multiply matrices.");
    }

    Matrix result(this->rows, rhs.cols);

    for (size_t i = 0; i < this->rows; i++) {
      for (size_t j = 0; j < rhs.cols; j++) {
        int sum = std::inner_product(this->arr.begin() + i * cols,
                                     this->arr.begin() + (i + 1) * cols,
                                     rhs.arr.begin() + j, 0);
        result.arr[i * result.cols + j] += sum;
      }
    }

    return result;
  }

  void print() const {
    auto view = std::views::enumerate(this->arr);
    std::for_each(view.begin(), view.end(), [](const auto &tuple) {
      if (std::get<0>(tuple) % 2 == 0)
        std::clog << '\n' << std::get<1>(tuple) << ' ';
      else
        std::clog << std::get<1>(tuple) << ' ';
    });
    std::clog << '\n';
  }
};

int main() {
  Matrix A(2, 2, {1, 2, 1, 2});
  Matrix B(2, 2, {1, 2, 1, 2});
  Matrix C = A * B;
  C.print();
}
