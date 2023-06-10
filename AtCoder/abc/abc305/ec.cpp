#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MAX_N = 2e5+5;
vector<int> G[MAX_N];
int dp[MAX_N];

struct Guard {
    int v, h;
    bool operator<(const Guard& a) const {
        return h < a.h;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<Guard> guards(K);
    for (int i = 0; i < K; i++) {
        cin >> guards[i].v >> guards[i].h;
        guards[i].v--;
    }

    sort(guards.begin(), guards.end());
    fill(dp, dp+N, INF);

    for (auto guard : guards) {
        if (dp[guard.v] <= guard.h) continue;

        queue<pair<int, int>> que;
        dp[guard.v] = guard.h;
        que.push({guard.v, guard.h});

        while (!que.empty()) {
            auto [v, h] = que.front(); que.pop();
            if (!h) continue;
            for (auto nv : G[v]) {
                if (dp[nv] <= h-1) continue;
                dp[nv] = h-1;
                que.push({nv, h-1});
            }
        }
    }

    for (int v = 0; v < N; v++) {
        if (dp[v] > 0) {
            cout << v+1 << "\n";
        }
    }

    return 0;
}