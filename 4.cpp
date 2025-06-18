#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Permutation(const vector<int>& permutation, const vector<int>& vec) {
    vector<int> result(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        result[i] = vec[permutation[i] - 1];
    }
    return result;
}

vector<int> InversePermutation(const vector<int>& permutation) {
    vector<int> inverse(permutation.size());
    for (int i = 0; i < permutation.size(); ++i) {
        inverse[permutation[i] - 1] = i + 1;
    }
    return inverse;
}

vector<int> permutationPower(const vector<int>& permutation, int power) {
    vector<int> current = permutation;
    vector<int> result(permutation.size());
    for (int i = 0; i < result.size(); ++i) {
        result[i] = i + 1;
    }
    
    while (power > 0) {
        if (power % 2 == 1) {
            result = Permutation(current, result);
        }
        current = Permutation(current, current);
        power /= 2;
    }
    return result;
}

int main() {
    cout << "Введите длину слова и количество шифрований: ";
    int n, k;
    cin >> n >> k;
    
    cout << "Введите перестановку: ";
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }
    
    cout << "Введите зашифрованное слово: ";
    string line;
    cin >> line;
    
    vector<int> inverse = InversePermutation(permutation);
    
    vector<int> totalInverse = permutationPower(inverse, k);
    
    string original(n, ' ');
    for (int i = 0; i < n; ++i) {
        original[i] = line[totalInverse[i] - 1];
    }

    cout << "Исходное слово: " << original << '\n';

    return 0;
}
