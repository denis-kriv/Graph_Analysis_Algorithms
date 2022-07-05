#include <iostream>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

double prim(pair<int, int>* points, int n) {
    double result = 0, inf = 30000, dist, dists[n];
    auto cmp = [&](int i, int j) { return make_pair(dists[i], i) < make_pair(dists[j], j); };
    set<int, decltype(cmp)> free(cmp);

    for (int i = 0; i < n; i++) {
        dists[i] = inf;
        free.insert(i);
    }

    while (not free.empty()) {
        int v = *free.begin();
        free.erase(v);
        result += dists[v];
        set<int> changed;
        for (int w : free) {
            dist = sqrt(pow(points[v].first - points[w].first, 2) + pow(points[v].second - points[w].second, 2));
            if (dists[w] > dist) {
                dists[w] = dist;
                changed.insert(w);
            }
        }
        for (int w: changed) {
            free.erase(w);
            free.insert(w);
        }
    }

    return result - inf;
}

int main() {
    int n, x, y;
    cin >> n;
    pair<int, int> points[n];
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    cout << fixed << setprecision(3) << prim(points, n);
}
