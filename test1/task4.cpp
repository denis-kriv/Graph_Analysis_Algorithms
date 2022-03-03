#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>* g, vector<int>& result, short int* colors, int v) {
    colors[v] = 1;

    for (int i : g[v]) {
        if (colors[i] == 1 or colors[i] == 0 and not dfs(g, result, colors, i)) {
            return false;
        }
    }

    result.push_back(v);
    colors[v] = 2;
    return true;
}

int main() {
    int n, m, src, trg;
    cin >> n >> m;
    short int colors[n];
    for (int i = 0; i < n; i++) {
        colors[i] = 0;
    }
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        cin >> src >> trg;
        g[src - 1].push_back(trg - 1);
    }
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (colors[i] == 0 and not dfs(g, result, colors, i)) {
            cout << -1;
            return 0;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << result[i] + 1 << ' ';
    }

    return 0;
}
