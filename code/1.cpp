#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Введите высоту пирамиды: ";
    std::cin>>n;
    
    std::vector<std::vector<int>> pyr(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            pyr[i].push_back(std::rand() % 1000);
            
        }
    }
    
    std::cout << "\nПирамида: " << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << pyr[i][j] << " ";
            
        }
        std::cout << '\n';
    }
    std::vector<std::vector<int>> sum = pyr;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < i; j++ ) {
            sum[i][j] += std::min(sum[i+1][j], sum[i+1][j+1]); 
        }
    }
    
    std::cout << "Минимальная сумма: " << sum[0][0] << '\n';
    
    std::cout << pyr[0][0] << " ";
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (sum[i][j] < sum[i][j+1]) {
            std::cout << pyr[i][j] << " ";
        } else {
            std::cout << pyr[i][j+1] << " ";
            j++;
        }
        
    }
    return 0;
}
