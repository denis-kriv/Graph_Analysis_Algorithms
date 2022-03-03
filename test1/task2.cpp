#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int> g[100], bool used[100], int v) {
    used[v] = true;
    int result = 1;

    for (int i = 0; i < g[v].size(); i++) {
        if (!used[g[v][i]]) {
            result += dfs(g, used, g[v][i]);
        }
    }

    return result;
}

int main() {
    int n, m, src, trg;
    vector<int> g[100];
    bool used[100];

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> src >> trg;
        g[src - 1].push_back(trg - 1);
        g[trg - 1].push_back(src - 1);
    }

    for (int i = 1; i < n; i++) {
        used[i] = false;
    }

    cout << ((dfs(g, used, 0) == n) ? "YES" : "NO");

    return 0;
}
