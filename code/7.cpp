#include <iostream>
#include <cctype> // для isdigit() и isupper()

using namespace std;

int main() {
    string plate;
    cin >> plate;
    
    if (plate.length() != 6) {
        cout << "No";
        return 0;
    }
    
    if (!isupper(plate[0])) {
        cout << "No";
        return 0;
    }
    
    for (int i = 1; i <= 3; ++i) {
        if (!isdigit(plate[i])) {
            cout << "No";
            return 0;
        }
    }
    
    for (int i = 4; i <= 5; ++i) {
        if (!isupper(plate[i])) {
            cout << "No";
            return 0;
        }
    }
    
    cout << "Yes";
    return 0;
}
