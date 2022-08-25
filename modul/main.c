#include <iostream>
#include <climits>

using namespace std;

int main() {
    int sum, max = INT_MIN, index;
    int(*a)[4];
    a = new int[4][4];
    cout << "Enter a matrix:\n";
    for (int i = 0; i < 4; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> ((a + i) + j);
            sum += ((a + 0) + j);
            if (a[i][j] > max) {
                max = ((a + i) + j);
                index = i;
            }
        }
    }
    if (max == sum) {
        for (int j = 0; j < 4; j++) {
            swap(((a + 0) + j), ((a + index) + j));
        }
    }
    cout << "Output of the program:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << ((a + i) + j) << " ";
        }
        cout << "\n";
    }
    return 0;
}
