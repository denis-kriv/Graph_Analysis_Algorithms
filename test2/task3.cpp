#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const long long inf = LLONG_MAX - 1000000000000000;

void dfs(vector<int>* g, bool* neg, int src) {
    if (not neg[src]) {
        neg[src] = true;
        for (int v : g[src]) {
            dfs(g, neg, v);
        }
    }
}

void bellman_ford(int n, int m, vector<int>* g, pair<pair<int, int>, long long>* es, int src) {
    long long dists[n];
    int step = 0;
    bool changed = true, neg[n];
    for (int i = 0; i < n; i++) {
        dists[i] = i == src ? 0 : inf;
        neg[i] = false;
    }

    while (step < n and changed) {
        changed = false;

        for (int i = 0; i < m; i++) {
            if (dists[es[i].first.first] < inf and dists[es[i].first.second] > dists[es[i].first.first] + es[i].second) {
                if (step == n - 1) {
                    dfs(g, neg, es[i].first.first);
                } else {
                    dists[es[i].first.second] = max(-inf, dists[es[i].first.first] + es[i].second);
                    changed = true;
                }
            }
        }

        step += 1;
    }

    for (int i = 0; i < n; i++) {
        if (dists[i] == inf) {
            cout << '*' << '\n';
        } else if (neg[i]) {
            cout << '-' << '\n';
        } else {
            cout << dists[i] << '\n';
        }
    }
}

int main() {
    int n, m, src, f, t;
    long long w;
    cin >> n >> m >> src;
    vector<int> g[n];
    pair<pair<int, int>, long long> es[m];

    for (int i = 0; i < m; i++) {
        cin >> f >> t >> w;
        g[f - 1].push_back(t - 1);
        es[i] = make_pair(make_pair(f - 1, t - 1), w);
    }

    bellman_ford(n, m, g, es, src - 1);
}
