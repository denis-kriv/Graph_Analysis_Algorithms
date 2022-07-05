#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int root(int* p, int x) {
    return (x == p[x]) ? x : (p[x] = root(p, p[x]));
}

void join(int* p, int* r, int x, int y) {
    int rootX = root(p, x), rootY = root(p, y);
    if (r[rootX] >= r[rootY]) {
        p[rootY] = rootX;
        r[rootX] += int(r[rootX] == r[rootY]);
    } else {
        p[rootX] = rootY;
    }
}

int kruskal(pair<pair<int, int>, int>* edges, int n, int m) {
    int result = 0, p[n], r[n];
    for (int i = 0; i < n; i++) {
        p[i] = i, r[i] = 0;
    }

    sort(edges, edges + m,
         [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) { return x.second < y.second; });
    for (int i = 0; i < m; i++) {
        int rootSrc = root(p, edges[i].first.first), rootTrg = root(p, edges[i].first.second);
        if (rootSrc != rootTrg) {
            join(p, r, rootSrc, rootTrg);
            result += edges[i].second;
        }
    }
    return result;
}

int main() {
    int n, m, src, trg, w;
    cin >> n >> m;
    pair<pair<int, int>, int> edges[m];
    for (int i = 0; i < m; i++) {
        cin >> src >> trg >> w;
        edges[i] = make_pair(make_pair(src - 1, trg - 1), w);
    }
    cout << kruskal(edges, n, m);
}
