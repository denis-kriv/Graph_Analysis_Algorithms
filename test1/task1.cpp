#include <iostream>

using namespace std;

int main() {
    int n, t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (j <= i && t == 1) {
                cout << j + 1 << ' ' << i + 1 << '\n';
            }
        }
    }
    return 0;
}
