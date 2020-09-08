#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> row(n), col(n);
    rep(i, n){
        row[i] = i;
        col[i] = i;
    }

    int transed = 0;
    rep(_, q){
        int cmd;
        cin >> cmd;

        if(cmd == 3){
            // swap(row, col);
            transed = 1 - transed;
        }
        else{
            int a, b;
            cin >> a >> b;
            --a;
            --b;

            if(cmd == 2) swap(row[a], row[b]);
            if(cmd == 1) swap(col[a], col[b]);
            if(cmd == 4){
                if(transed) cout << n*row[b] + col[a] << endl;
                else cout << n*row[a] + col[b] << endl;
            }
        }
        cout << "row: ";
        rep(i, n) cout << row[i] << " ";
        cout << endl;
        cout << "col: ";
        rep(i, n) cout << col[i] << " ";
        cout << endl;
    }

    return 0;
}