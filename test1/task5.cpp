#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>* g, vector<int>& result, short int* colors, int v) {
    colors[v] = 1;

    for (int i : g[v]) {
        if (colors[i] == 1) {
            result.push_back(i);
            result.push_back(v);
            return true;
        }
        if (colors[i] == 0 and dfs(g, result, colors, i)) {
            result.push_back(v);
            return true;
        }
    }

    colors[v] = 2;
    return false;
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
        if (colors[i] == 0 and dfs(g, result, colors, i)) {
            cout << "YES" << '\n';
            bool f = false;
            for (int j = result.size() - 1; j > 0; j--) {
                if (f) {
                    cout << result[j] + 1 << ' ';
                }
                if (result[j] == result[0]) {
                    cout << result[j] + 1 << ' ';
                    f = true;
                }
            }
            return 0;
        }
    }
    cout << "NO";

    return 0;
}
