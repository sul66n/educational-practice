#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Введите количество улиц и количество запросов: ";
    
    int n, k;
    cin >> n >> k;

    vector<int> streets(n + 1, 0);

    for (int i = 0; i < k; ++i) {
        cout << "\nЗапрос " << (i + 1) << " из " << k << ": ";

        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            streets[a] += b;
            cout << "Добавлено " << b << " мм снега на улицу " << a << '\n';
        } else if (type == 2) {
            int sum = 0;
            for (int j = a; j <= b; ++j) {
                sum += streets[j];
            }
            cout << "Сумма снега с улицы " << a << " по " << b << " = " << sum << '\n';
        } else {
            cout << "Напишите 1 или 2\n";
            --i;
        }
    }

    return 0;
}
