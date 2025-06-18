#include <iostream>
#include <vector>
#include <limits>

int main() {
  int h, w;
  std::cout << "Введите высоту и ширину матрицы: ";
  std::cin >> h >> w;

  std::vector<std::vector<int>> matrix(h, std::vector<int>(w));

  std::cout << "Введите значения матрицы построчно (только 0 и 1):\n";
  for (int i = 0; i < h; ++i) {
    std::cout << "Строка " << i << ": ";
    for (int j = 0; j < w; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  int min_row = std::numeric_limits<int>::max();
  int max_row = std::numeric_limits<int>::min();
  int min_col = std::numeric_limits<int>::max();
  int max_col = std::numeric_limits<int>::min();

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (matrix[i][j] == 1) {
        if (i < min_row) min_row = i;
        if (i > max_row) max_row = i;
        if (j < min_col) min_col = j;
        if (j > max_col) max_col = j;
      }
    }
  }

  std::cout << "\nКоординаты ограничивающего прямоугольника:\n";
  std::cout << min_row << " " << min_col << " " << max_row << " " << max_col << "\n";

  return 0;
}
