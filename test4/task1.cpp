#include <iostream>
#include <vector>

using namespace std;

int root(int* p, int x) {
    return (x == p[x]) ? x : (p[x] = root(p, p[x]));
}

void join(int* p, int* r, int* anc, int x, int y, int new_anc) {
    int rootX = root(p, x), rootY = root(p, y);
    if (r[rootX] >= r[rootY]) {
        p[rootY] = rootX;
        r[rootX] += int(r[rootX] == r[rootY]);
        anc[rootX] = new_anc;
    } else {
        p[rootX] = rootY;
        anc[rootY] = new_anc;
    }
}

void dfs (int n, vector<int>* g, vector<pair<int, int>>* q, int* p, int* r, int* anc, bool* used, int* result, int v) {
    p[v] = v;
    anc[v] = v;
    used[v] = true;
    for (int w: g[v]) {
        if (not used[w]) {
            dfs(n, g, q, p, r, anc, used, result, w);
            join(p, r, anc, v, w, v);
        }
    }
    for (pair<int, int> query: q[v]) {
        if (used[query.first]) {
            result[query.second] = anc[root(p, query.first)] + 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int v, r[n];
    bool used[n];
    vector<int> g[n];
    for (int i = 1; i < n; i++) {
        r[i] = 0, used[i] = false;
        cin >> v;
        g[v - 1].push_back(i);
    }

    int m;
    cin >> m;
    int w;
    vector<pair<int, int>> q[n];
    for (int i = 0; i < m; i++) {
        cin >> v >> w;
        q[v - 1].emplace_back(w - 1, i);
        q[w - 1].emplace_back(v - 1, i);
    }

    int p[n], anc[n], result[m];
    dfs(n, g, q, p, r, anc, used, result, 0);

    for (int i = 0; i < m; i++) {
        cout << result[i] << '\n';
    }
}