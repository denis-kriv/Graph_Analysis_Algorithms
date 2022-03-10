#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int g[n][n], dists[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            dists[i][j] = g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (int w = 0; w < n; w++) {
                if (dists[v][w] > dists[v][i] + dists[i][w]) {
                    dists[v][w] = dists[v][i] + dists[i][w];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dists[i][j] << ' ';
        }
        cout << '\n';
    }
}
