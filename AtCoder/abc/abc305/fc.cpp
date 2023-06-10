#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAX_N = 105;
vector<int> adj[MAX_N];
bool vis[MAX_N];

void dfs(int v) {
    vis[v] = true;
    cout << v+1 << endl;

    string s;
    cin >> s;
    if (s == "OK" || s == "-1") {
        exit(0);
    }

    stringstream ss(s);
    int k;
    ss >> k;
    vector<int> to;
    for (int i = 0; i < k; i++) {
        int u;
        ss >> u;
        u--;
        to.push_back(u);
        if (!vis[u]) {
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
    }

    for (int u : adj[v]) {
        if (!vis[u]) {
            dfs(u);
            break;
        }
    }

    cout << v+1 << endl;
    cin >> s;
    if (s == "OK" || s == "-1") {
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    dfs(0);

    return 0;
}