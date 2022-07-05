#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int maxN = 20000;
vector<int> g[maxN];
vector<pair<int, int>> edges;
unordered_set<int> bridges[maxN];
bool used[maxN];
int timeIn[maxN], up[maxN], t = 0;

int dfs(int parent, int src) {
    timeIn[src] = up[src] = t++;
    used[src] = true;
    int bridges_count = 0;
    for (int& trg : g[src]) {
        if (used[trg]) {
            up[src] = trg != parent ? min(timeIn[trg], up[src]) : up[src];
        } else {
            bridges_count += dfs(src, trg);
            up[src] = min(up[src], up[trg]);
        }
    }
    if (up[src] >= timeIn[src]) {
        bridges[min(parent, src)].insert(max(parent, src));
    }
    return bridges_count;
}

int main() {
    int n, m, src, trg;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        used[n] = false;
    }

    for (int i = 0; i < m; i++) {
        cin >> src >> trg;
        g[src - 1].push_back(trg - 1);
        g[trg - 1].push_back(src - 1);
        edges.push_back(make_pair(min(src - 1, trg - 1), max(src - 1, trg - 1)));
    }

    cout << dfs(-1, 0) << '\n';
    for (int i = 0; i < m; i++) {
        if (bridges[edges[i].first].find(edges[i].second) != bridges[edges[i].first].end()) {
            cout << i + 1 << ' ';
        }
    }
}