#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<int, int> penalty;
    map<int, int> is_ac;
    int res1 = 0;
    int res2 = 0;
    rep(i, m){
        int p;
        string s;
        cin >> p >> s;

        if(s=="WA") {
            if(!is_ac[p]) ++penalty[p];
        }
        else{
            is_ac[p] = 1;
        }
    }

    for(auto itr = is_ac.begin(); itr != is_ac.end(); ++itr){
        int p = itr->first;
        if(is_ac[p]) {
            ++res1;
            res2 += penalty[p];
        }
    }

    cout << res1 << " " << res2 << endl;


    return 0;
}