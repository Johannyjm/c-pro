#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


vector<int> odd;
vector<int> even;

int dfs(int x, int last = -1, int d = 0, vector<vector<int>> edge){
    if(d%2) odd.push_back(x);
    else even.push_back(x);

    for(int nxt: edge[x]){
        if(nxt == last) continue;
        else dfs(nxt, x, d+1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> edge(n-1);

    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(0);

    vector<vector<int>> nums(3);
    rep1(i, n+1) nums[i%3].push_back(i);

    vector<int> res(n, -1);
    int zerocnt = nums[0].size();
    if(even.size() <= zerocnt){
        for(int even_node: even){
            res[even_node] = nums[0]
        }
    }

    return 0;
}