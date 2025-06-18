#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cout << "Введите количество запросов: ";
  std::cin >> n;

  std::vector<int> results;

  for (int i = 0; i < n; ++i) {
    int a, b, x, y;
    std::cout << "\nЗапрос " << (i + 1) << ":\n";
    std::cout << "Введите количество микроконтроллеров типа A: ";
    std::cin >> a;
    std::cout << "Введите количество микроконтроллеров типа B: ";
    std::cin >> b;
    std::cout << "Введите количество модулей управления типа 1: ";
    std::cin >> x;
    std::cout << "Введите количество модулей управления типа 2: ";
    std::cin >> y;

    int b1 = std::min(b, x);
    b -= b1;
    x -= b1;

    int a1 = std::min(a, x);  // A + 1
    a -= a1;
    x -= a1;

    int a2 = std::min(a, y);  // A + 2
    a -= a2;
    y -= a2;

    results.push_back(b1 + a1 + a2);
  }

  std::cout << "\nМаксимальное количество работающих пар для каждого запроса:\n";
  for (int r : results) {
    std::cout << r << " ";
  }
  std::cout << "\n";

  return 0;
}
