#include <iostream>

using namespace std;

const int inf = 100001;

int main() {
    int d = -inf, r = inf, ex, n, e;
    cin >> n;

    int dists[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> e;
            dists[i][j] = e == -1 ? inf : e;
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
        ex = -inf;
        for (int j = 0; j < n; j++) {
            d = max(d, dists[i][j]);
            ex = max(ex, dists[i][j]);
        }
        r = min(r, ex);
    }
    cout << d << '\n' << r;
}
