#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int>* g, int n, int v) {
    queue<int> q;
    int distances[n];
    bool used[n];
    int result = 0;

    q.push(v);
    distances[v] = 0;
    for (int i = 0; i < n; i++) {
        used[i] = i == v;
    }

    while (not q.empty()) {
        for (int i : g[q.front()]) {
            if (not used[i]) {
                q.push(i);
                distances[i] = distances[q.front()] + 1;
                used[i] = true;
                if (i > v) {
                    result += distances[i];
                }
            }
        }
        q.pop();
    }

    return result;
}

int main() {
    int result = 0, n, m, src, trg;
    cin >> n >> m;
    vector<int> g[n];
    for (int i = 0; i < m; i++) {
        cin >> src >> trg;
        g[src - 1].push_back(trg - 1);
        g[trg - 1].push_back(src - 1);
    }

    for (int i = 0; i < n; i++) {
        result += bfs(g, n, i);
    }
    cout << result;

    return 0;
}
