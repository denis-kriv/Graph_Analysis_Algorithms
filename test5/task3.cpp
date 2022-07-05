#include <iostream>
#include <vector>

using namespace std;

long long TIME = 0;

void dfs(long long lg, vector<long long>* g, long long* tin, long long* tout, vector<long long>* jmp, long long p, long long v) {
    tin[v] = ++TIME;
    jmp[v][0] = p;
    for (int i = 1; i <= lg; i++) {
        jmp[v][i] = jmp[jmp[v][i - 1]][i - 1];
    }
    for (long long w: g[v]) {
        if (w != p) {
            dfs(lg, g, tin, tout, jmp, v, w);
        }
    }
    tout[v] = ++TIME;
}

long long lca(long long lg, const long long* tin, const long long* tout, vector<long long>* jmp, long long a, long long b) {
    if (tin[a] <= tin[b] && tout[a] >= tout[b]) return a;
    if (tin[b] <= tin[a] && tout[b] >= tout[a]) return b;
    for (long long i = lg; i >= 0; i--)
        if (not (tin[jmp[a][i]] <= tin[b] && tout[jmp[a][i]] >= tout[b]))
            a = jmp[a][i];
    return jmp[a][0];
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long v;
    vector<long long> g[n];
    for (int i = 1; i < n; i++) {
        cin >> v;
        g[v].push_back(i);
    }
    long long as[2 * m + 1];
    cin >> as[1] >> as[2];
    long long x, y, z;
    cin >> x >> y >> z;
    for (int i = 3; i <= 2 * m; i++) {
        as[i] = (x * as[i - 2] + y * as[i - 1] + z) % n;
    }

    long long lg = 1;
    while ((1 << lg) <= n) lg++;
    long long tin[n], tout[n];
    vector<long long> jmp[n];
    for (int i = 0; i < n; i++) jmp[i].resize(lg + 1);
    dfs(lg, g, tin, tout, jmp, 0, 0);

    long long result = 0;
    v = 0;
    for (int i = 1; i <= m; i++) {
        v = lca(lg, tin, tout, jmp, (as[2 * i - 1] + v) % n, as[2 * i]);
        result += v;
    }
    cout << result;
}
