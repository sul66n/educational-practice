#include <iostream>
#include <vector>
#include <queue>

int main() {
  std::cout << "Введите количество узлов сети и количество соединений: ";
  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> adj(N + 1);

  std::cout << "\nВведите " << M << " пар соединений (узлы, связанные линией):\n";
  for (int i = 0; i < M; ++i) {
    std::cout << "Соединение " << (i + 1) << ": ";
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<bool> visited(N + 1, false);
  int components = 0;

  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) {
      components++;
      std::queue<int> q;
      q.push(i);
      visited[i] = true;

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
          if (!visited[v]) {
            visited[v] = true;
            q.push(v);
          }
        }
      }
    }
  }

  std::cout << "\nМинимальное количество линий для соединения сети: ";
  std::cout << (components - 1) << "\n";

  return 0;
}
