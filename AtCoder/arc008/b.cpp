#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string name, kit;
    cin >> name >> kit;

    vector<int> exists(26, 0);
    for(char c : kit) ++exists[c - 'A'];

    int res = 1;
    rep(i, name.size()){
        if(exists[name[i] - 'A'] == 0){
            for(char c : kit) ++exists[c - 'A'];
            ++res;

            if(exists[name[i] - 'A'] == 0){
                cout << -1 << endl;
                return 0;
            } 
            --exists[name[i] - 'A'];
        }
        else --exists[name[i] - 'A'];
    }

    cout << res << endl;

    return 0;
}