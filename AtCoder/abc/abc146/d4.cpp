#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> a(n-1), b(n-1);
    rep(i, n-1){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];

        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    vector<int> seen(n, 0);

    map<pair<int, int>, int> res;
    int max_color = 0;
    while(!q.empty()){
        int v = q.front().first;
        int ng_color = q.front().second;
        q.pop();

        seen[v] = 1;

        unordered_set<int> ng_colors;
        ng_colors.insert(ng_color);

        int color = 1;
        for(auto nv: g[v]){
            if(seen[nv]) continue;

            while(1){
                if(ng_colors.count(color)) ++color;
                else break;
            }
            res[make_pair(v, nv)] = color;
            q.push(make_pair(nv, color));

            max_color = max(max_color, color);
            ng_colors.insert(color);
        }
    }

    cout << max_color << endl;
    rep(i, n-1){
        cout << res[make_pair(a[i], b[i])] << endl;
    }


    return 0;
}