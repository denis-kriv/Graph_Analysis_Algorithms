#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dijkstra(vector<pair<int, int>>* g, int n, int src, int trg) {
    int dists[n], used[n], cur;

    for (int i = 0; i < n; i++) {
        dists[i] = i == src ? 0 : -1;
        used[i] = false;
    }

    auto cmp = [&](int i, int j) { return make_pair(dists[i], i) < make_pair(dists[j], j); };
    set<int, decltype(cmp)> nodes(cmp);
    nodes.insert(src);

    while (not nodes.empty()) {
        cur = *nodes.begin();
        nodes.erase(cur);
        used[cur] = true;

        for (pair<int, int> p : g[cur]) {
            if (not used[p.first] and dists[p.first] == -1 or dists[p.first] > dists[cur] + p.second) {
                if (dists[p.first] != -1) {
                    nodes.erase(p.first);
                }
                dists[p.first] = dists[cur] + p.second;
                nodes.insert(p.first);
            }
        }
    }

    return dists[trg];
}

int main() {
    int n, m, src, trg, v1, v2, w;
    cin >> n >> m >> src >> trg;

    vector<pair<int, int>> g[n];
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> w;
        g[v1 - 1].emplace_back(v2 - 1, w);
        g[v2 - 1].emplace_back(v1 - 1, w);
    }

    cout << dijkstra(g, n, src - 1, trg - 1);
}
