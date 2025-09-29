#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(i + 1);
    for (int j = 0; j <= i; j++) {
      std::cin >> a[i][j];
    }
  }

  // Копируем в dp
  std::vector<std::vector<int>> dp = a;

  // Считаем минимальные суммы (снизу вверх)
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] += std::min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }

  std::cout << dp[0][0] << "\n"; // минимальное время

  // Восстанавливаем путь
  int col = 0;
  std::cout << a[0][0];
  for (int i = 1; i < n; i++) {
    if (dp[i][col] <= dp[i][col + 1]) {
      std::cout << " " << a[i][col];
    } else {
      col++;
      std::cout << " " << a[i][col];
    }
  }
  std::cout << "\n";

  return 0;
}