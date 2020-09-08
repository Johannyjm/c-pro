#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> prob(m, n);
    vector<vector<int>> score(n, vector<int>(m, 0));

    rep(_, q){
        int cmd;
        cin >> cmd;

        if(cmd == 1){
            int a;
            cin >> a;
            --a;
            int res = 0;
            rep(i, m) res += prob[i] * score[a][i];
            cout << res << endl;
        }

        else{
            int b, c;
            cin >> b >> c;
            --b;
            --c;

            score[b][c] = 1;
            --prob[c];
        }
    }

    return 0;
}